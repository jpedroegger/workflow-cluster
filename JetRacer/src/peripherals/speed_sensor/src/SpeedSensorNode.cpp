#include "SpeedSensorNode.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <functional>
#include <rclcpp/logging.hpp>

SpeedSensorNode::SpeedSensorNode() : rclcpp::Node("speed_sensor")
{
    raw_can_subscriber_ = this->create_subscription<custom_msgs::msg::CanFrame>(
        "raw_can", 10,
        std::bind(&SpeedSensorNode::writeSpeed, this, std::placeholders::_1));
    speed_publisher_ = this->create_publisher<std_msgs::msg::UInt8>(
        "speed_sensor_readings", 10);

    RCLCPP_INFO(this->get_logger(), "Starting speed sensor node");
}

SpeedSensorNode::~SpeedSensorNode() {}

/**
 * @brief function called upon receiving a CAN_frame. reads the can_raw topic
 * and publishes the speed in a different topic
 *
 * @param can_frame
 */
void SpeedSensorNode::writeSpeed(
    const custom_msgs::msg::CanFrame::SharedPtr can_frame)
{
    std_msgs::msg::UInt8 speed_msg;

    if (can_frame->id == SPEED_SENSOR_ID)
    {
        speed_msg.data = can_frame->data.front();
        speed_publisher_->publish(speed_msg);
    }
}
