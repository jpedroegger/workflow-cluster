#include <CameraNode.hpp>
#include <image_transport/image_transport.hpp>
#include <libcamera/camera_manager.h>
#include <libcamera/framebuffer_allocator.h>
#include <libcamera/libcamera.h>
#include <libcamera/request.h>
#include <opencv2/opencv.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
#include <sensor_msgs/msg/image.hpp>

using namespace std::chrono_literals;

static void requestComplete(Request* request)
{
    if (request->status() == Request::RequestCancelled)
        return;

    loop.callLater(std::bind(&processRequest, request));
}

CameraNode::CameraNode() : Node("Camera_node")
{
    rclcpp::QoS qos(rclcpp::KeepLast(60));
    qos.reliable();

    timer_ =
        this->create_timer(100ms, std::bind(&CameraNode::captureImage, this));
    raw_out_publisher_ =
        this->create_publisher<sensor_msgs::msg::Image>("raw_camera", qos);
    camera_manager_ = std::make_unique<CameraManager>();

    if (camera_manager_->start())
    {
        RCLCPP_ERROR(this->get_logger(), "Fail starting camera manager");
        throw std::runtime_error("fail starting camera manager");
    }
    auto cameras = camera_manager_->cameras();
    if (cameras.empty())
    {
        RCLCPP_ERROR(this->get_logger(), "Couldnt find any camera");
        camera_manager_->stop();
        throw std::runtime_error("no camera detected");
    }

    // get camera from the manager.
    std::string camera_id = cameras[0]->id();
    camera_ = camera_manager_->get(camera_id);
    camera_->acquire(); // lock the cam

    allocator_ = new FrameBufferAllocator(camera_);
    configureStreams_();
    // Assuming CameraNode is the class and this points to an instance of
    // CameraNode.
    camera_->requestCompleted.connect(
        [this](Request* request) { this->HandleRequestCompleted_(request); });

    camera_->start();

    RCLCPP_INFO(this->get_logger(), "Starting camera node");
}

CameraNode::~CameraNode()
{
    // TODO : stop the cam, free buffer
    for (auto stream : streams_)
        allocator_->free(stream);
    delete allocator_;
    camera_->release();
    camera_.reset();
    camera_manager_->stop();
}

void CameraNode::configureStreams_()
{
    // Generate and validate configs
    std::unique_ptr<CameraConfiguration> config =
        camera_->generateConfiguration(
            {StreamRole::Viewfinder, StreamRole::Raw});

    StreamConfiguration& stream_config = config->at(0);
    StreamConfiguration& stream_config_raw = config->at(1);

    stream_config.size.width = 2304;
    stream_config.size.height = 1296;
    stream_config.pixelFormat = PixelFormat::fromString("YUV420");

    stream_config_raw.size.width = 2304;
    stream_config_raw.size.height = 1296;
    stream_config_raw.pixelFormat = PixelFormat::fromString("SBGGR10_CSI2P");

    config->validate();
    camera_->configure(config.get());

    // allocate buffers
    for (StreamConfiguration& cfg : *config)
    {
        int ret = allocator_->allocate(cfg.stream());
        if (ret)
        {
            RCLCPP_ERROR(this->get_logger(), "Fail allocating stream buffers");
            throw std::runtime_error("fail allocating stream buffers");
        }
    }

    // create the streams
    streams_.push_back(stream_config.stream());
    streams_.push_back(stream_config_raw.stream());
}

void CameraNode::captureImage()
{
    const std::vector<std::unique_ptr<FrameBuffer>>& buffers =
        allocator_->buffers(streams_.at(0));

    std::unique_ptr<Request> request = camera_->createRequest();
    if (!request)
    {
        RCLCPP_ERROR(this->get_logger(), "Fail creating request");
        return;
    }

    // first buffer for simplicity (buffers are reused automatically)
    const std::unique_ptr<FrameBuffer>& buffer = buffers[0];
    int ret = request->addBuffer(streams_.at(0), buffer.get());
    if (ret < 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to add buffer to request");
        return;
    }

    // Queue the request
    camera_->queueRequest(request.get());
}

void CameraNode::HandleRequestCompleted_(Request* request)
{
    if (request->status() != Request::RequestComplete)
    {
        RCLCPP_WARN(this->get_logger(), "Request was not completed succefully");
        return;
    }

    const std::map<const Stream*, FrameBuffer*>& buffers = request->buffers();
    auto it = buffers.find(streams_.at(0));
    if (it == buffers.end())
    {
        RCLCPP_ERROR(this->get_logger(), "No buffer found for stream");
        return;
    }

    FrameBuffer* buffer = it->second;
    // Access the data in the buffer
    const FrameMetadata& metadata = buffer->metadata();
    std::cout << " seq: " << std::setw(6) << std::setfill('0')
              << metadata.sequence << " timestamp: " << metadata.timestamp
              << " bytesused: ";

    unsigned int nplane = 0;
    for (const FrameMetadata::Plane& plane : metadata.planes())
    {
        std::cout << plane.bytesused;
        if (++nplane < metadata.planes().size())
            std::cout << "/";
    }

    std::cout << std::endl;
}
