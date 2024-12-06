#pragma once

#include "PCA9685Driver.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <std_msgs/msg/u_int8.hpp>

#define MIN_COUNT 410  // 10% duty cycle
#define MAX_COUNT 3680 // 90% duty cycle
#define PCA_MOTORS_ADDRESS 0x60

class DcMotorsNode : public rclcpp::Node
{
    public:
        DcMotorsNode();
        ~DcMotorsNode();

        void initPCA9685();

    private:
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr speed_subscriber_;
        std::shared_ptr<PCA9685Driver> pca9685_;

        void writeSpeed(const std_msgs::msg::UInt8::SharedPtr spedd);
};
