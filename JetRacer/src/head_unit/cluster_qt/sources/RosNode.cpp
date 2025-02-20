#include "RosNode.hpp"

RosNode::RosNode() : rclcpp::Node("ros_node"), battery_level_(0), speed_(0)
{
    battery_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "battery_percentage", 10, [this](std_msgs::msg::Float64 battery_level)
        { battery_level_ = static_cast<int>(battery_level.data); });

    speed_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "speed_readings", 10, [this](std_msgs::msg::UInt8 msg)
        { speed_ = static_cast<int>(msg.data); });

    rpm_sub_ = this->create_subscription<std_msgs::msg::UInt32>(
        "rpm_readings", 10,
        [this](std_msgs::msg::UInt32 msg) { rpm_ = msg.data; });

    blinker_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
        "cmd_blinkers", 10,
        std::bind(&RosNode::setBlinkerState, this, std::placeholders::_1));
    
        wheel_angle_sub_ = this->create_subscription<std_msgs::msg::Float64>(
            "cmd_vel", 90,
            [this](const std_msgs::msg::Float64::SharedPtr msg) {
                wheel_angle_ = static_cast<float>(msg->data);
            });
}

int RosNode::getSpeed() const { return speed_; }

int RosNode::getBattery() const { return battery_level_; }

int RosNode::getRpm() const { return rpm_; }

float RosNode::getWheelAngle() const {return wheel_angle_; }

blinkerState RosNode::getBlinkerState() const { return blinker_state_; }

void RosNode::setBlinkerState(std_msgs::msg::UInt8 msg)
{
    switch (msg.data)
    {
    case 0x0:
        blinker_state_ = blinkerState::IDLE;
        break;
    case 0x1:
        blinker_state_ = blinkerState::TURN_RIGHT;
        break;
    case 0x2:
        blinker_state_ = blinkerState::TURN_LEFT;
        break;
    case 0x3:
        blinker_state_ = blinkerState::WARNINGS;
        break;
    default:
        RCLCPP_WARN(this->get_logger(), "Unrecognised blinker state");
        blinker_state_ = blinkerState::IDLE;
    }
}
