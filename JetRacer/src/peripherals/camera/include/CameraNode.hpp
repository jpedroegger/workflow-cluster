#pragma once

#include <libcamera/camera.h>
#include <libcamera/camera_manager.h>
#include <libcamera/libcamera.h>
#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <sensor_msgs/msg/image.hpp>

using namespace libcamera;

class CameraNode : public rclcpp::Node
{
    public:
        CameraNode();
        ~CameraNode();

        void captureImage();

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr
            raw_out_publisher_;
        std::unique_ptr<CameraManager> camera_manager_;
        std::shared_ptr<Camera> camera_;
        FrameBufferAllocator* allocator_;
        std::vector<Stream*> streams_;

        void configureStreams_();
        void allocateBuffers_();
        void HandleRequestCompleted_(Request* request);
};
