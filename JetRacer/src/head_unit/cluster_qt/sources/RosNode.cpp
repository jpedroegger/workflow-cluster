#include "RosNode.hpp"


/**
 * @brief Constructs a RosNode.
 *
 * This constructor initializes the ROS 2 node and sets up subscriptions for battery level,
 * speed, RPM, and blinker state.
 */
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
}


/**
 * @brief A Getter that returns the current speed of the vehicle.
 *
 * @return The current speed as an integer.
 */
int RosNode::getSpeed() const { return speed_; }

/**
 * @brief A Getter that returns the current battery level of the vehicle.
 *
 * @return The current battery level as an integer (0-100).
 */
int RosNode::getBattery() const { return battery_level_; }

/**
 * @brief A Getter that returns the current RPM of the vehicle.
 *
 * @return The current RPM as an integer.
 */
int RosNode::getRpm() const { return rpm_; }

/**
 * @brief A Getter that returns the current state of the blinkers.
 *
 * @return The current blinker state as a `blinkerState` enum value.
 */
blinkerState RosNode::getBlinkerState() const { return blinker_state_; }

/**
 * @brief A Setter that updates the blinker state based on the received message.
 *
 * This callback function is triggered whenever a new blinker state message is received.
 *
 * @param msg The message containing the new blinker state.
 */
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
