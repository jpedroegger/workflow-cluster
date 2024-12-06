#include "DisplayRoutineNode.hpp"

using namespace std::chrono_literals;

DisplayRoutineNode::DisplayRoutineNode() : rclcpp::Node("display_routine_node")
{
    timer_ = this->create_timer(
        30s, std::bind(&DisplayRoutineNode::updateDisplay, this));
    publisher_ =
        this->create_publisher<std_msgs::msg::String>("cmd_display", 10);
}

void DisplayRoutineNode::updateDisplay()
{
    // TODO: display the IP, battery level and cpu comsumption
}
