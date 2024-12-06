#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class DisplayRoutineNode : public rclcpp::Node
{
    public:
        DisplayRoutineNode();
        ~DisplayRoutineNode() = default;

    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

        void updateDisplay();
};
