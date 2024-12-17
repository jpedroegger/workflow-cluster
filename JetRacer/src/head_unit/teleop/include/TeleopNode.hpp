#pragma once

#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>

class TeleopNode : public rclcpp::Node
{
    public:
        TeleopNode();
        ~TeleopNode();

        void joyCallback(sensor_msgs::msg::Joy::SharedPtr joy_msg);

    private:
        rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_subscriber_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr
            twist_publisher_;
};
