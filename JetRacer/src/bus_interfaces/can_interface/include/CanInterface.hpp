#pragma once

#include "CanDriver.hpp"
#include "custom_msgs/msg/can_frame.hpp"
#include "custom_msgs/srv/can_service.hpp"
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <thread>

using sockcanpp::CanDriver;

class CanInterface : public rclcpp::Node
{
    public:
        CanInterface();
        ~CanInterface();

        void pollCanBus();

    private:
        std::shared_ptr<sockcanpp::CanDriver> can_driver_;
        rclcpp::Service<custom_msgs::srv::CanService>::SharedPtr can_service_;
        std::thread polling_thread_;
        rclcpp::Publisher<custom_msgs::msg::CanFrame>::SharedPtr publisher_;

        void handleCanRequest(
            const std::shared_ptr<custom_msgs::srv::CanService::Request>
                request,
            std::shared_ptr<custom_msgs::srv::CanService::Response> response);
};
