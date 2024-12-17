#include "TeleopNode.hpp"

TeleopNode::TeleopNode() : rclcpp::Node("teleop_node")
{
    rclcpp::QoS qos(20);
    qos.reliable();

    joy_subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", qos,
        std::bind(&TeleopNode::joyCallback, this, std::placeholders::_1));

    twist_publisher_ =
        this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
}

TeleopNode::~TeleopNode() {}

void TeleopNode::joyCallback(sensor_msgs::msg::Joy::SharedPtr joy_msg)
{
    auto twist_msg = geometry_msgs::msg::Twist();

    twist_msg.linear.x = joy_msg->axes[1];  // Left stick, vertical axis
    twist_msg.angular.z = joy_msg->axes[0]; // Left stick, horizontal axis

    // Publish the Twist message to /cmd_vel
    twist_publisher_->publish(twist_msg);
}
