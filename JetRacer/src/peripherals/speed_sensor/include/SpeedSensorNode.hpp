#pragma once

#include "custom_msgs/msg/can_frame.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <custom_msgs/srv/i2c_service.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <std_msgs/msg/u_int8.hpp>

#define SPEED_SENSOR_ID 0x00

class SpeedSensorNode : public rclcpp::Node
{
    public:
        SpeedSensorNode();
        ~SpeedSensorNode();

    private:
        rclcpp::Subscription<custom_msgs::msg::CanFrame>::SharedPtr
            raw_can_subscriber_;
        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr speed_publisher_;

        void writeSpeed(const custom_msgs::msg::CanFrame::SharedPtr can_frame);
};
