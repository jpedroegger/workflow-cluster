#pragma once

#include "PCA9685Driver.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <std_msgs/msg/u_int8.hpp>

#define MIN_COUNT 102
#define MAX_COUNT 510
#define PCA_SERVO_ADDRESS 0x40

class ServoNode : public rclcpp::Node
{
    public:
        ServoNode();
        ~ServoNode();

        void initPCA9685();

    private:
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr
            direction_subscriber_;
        std::shared_ptr<PCA9685Driver> pca9685_;

        void writeAngle(const std_msgs::msg::UInt8::SharedPtr direction);
};
