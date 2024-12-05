#pragma once

#include "CanDriver.hpp"
#include "custom_msgs/msg/can_frame.hpp"
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
        std::thread polling_thread_;
        rclcpp::Publisher<custom_msgs::msg::CanFrame>::SharedPtr publisher_;
};
