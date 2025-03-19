#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/u_int32.hpp>
#include <std_msgs/msg/u_int8.hpp>

enum class blinkerState
{
    IDLE,
    TURN_RIGHT,
    TURN_LEFT,
    WARNINGS,
};

/**
 * @brief The RosNode class represents a ROS 2 node for managing vehicle data.
 *
 * This class inherits from rclcpp::Node and subscribes to topics 
 * such as battery level and speed. It also includes methods to retrieve
 * the latest values of these parameters.
 */
class RosNode : public rclcpp::Node
{
    public:
        RosNode();
        ~RosNode() override = default;

        int             getSpeed() const;
        int             getBattery() const;
        int             getRpm() const;
        blinkerState    getBlinkerState() const;

    private:
        rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr battery_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr   speed_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt32>::SharedPtr  rpm_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr   blinker_sub_;

        void            setBlinkerState(std_msgs::msg::UInt8 msg);

        int             battery_level_{0};
        int             speed_{0};
        int             rpm_{0};
        blinkerState    blinker_state_{blinkerState::IDLE};
};
