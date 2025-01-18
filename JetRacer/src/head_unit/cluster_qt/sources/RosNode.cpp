#include "RosNode.hpp"

RosNode::RosNode() : rclcpp::Node("ros_node"), battery_level_(0), speed_(0)
{
    battery_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "battery_percentage", 10, [this](std_msgs::msg::Float64 battery_level)
        { battery_level_ = static_cast<int>(battery_level.data); });

    speed_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "speed_readings", 10, [this](std_msgs::msg::UInt8 msg)
        { speed_ = static_cast<int>(msg.data); });
}

int RosNode::getSpeed() const { return speed_; }

int RosNode::getBattery() const { return battery_level_; }
