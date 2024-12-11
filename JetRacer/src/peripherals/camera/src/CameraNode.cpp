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

CameraNode::CameraNode() : Node("Camera_node")
{
    rclcpp::QoS qos(rclcpp::KeepLast(60));
    qos.reliable();

    timer_ =
        this->create_timer(5s, std::bind(&CameraNode::publishRawCamera, this));
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

    RCLCPP_INFO(this->get_logger(), "Starting camera node");
}

CameraNode::~CameraNode() { camera_manager_->stop(); }

void CameraNode::publishRawCamera() {}
