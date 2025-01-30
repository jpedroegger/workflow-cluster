#pragma once

#include "std_msgs/msg/u_int8.hpp"
#include <custom_msgs/srv/can_service.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>

constexpr int BLINKERS_STATE_ID = 0x100;
constexpr int NODE_QOS = 10;

/**
 * @class BlinkersNode
 * @brief listens to blinker state topic and request the can interface to update
 * the blinkers .
 */
class BlinkersNode : public rclcpp::Node
{
    public:
        BlinkersNode();
        ~BlinkersNode() override = default;

    private:
        rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr
            blinker_state_subscriber_;
        rclcpp::Client<custom_msgs::srv::CanService>::SharedPtr can_client_;

        void writeBlinkersState(std_msgs::msg::UInt8 msg);
        void handleCanResponse(
            rclcpp::Client<custom_msgs::srv::CanService>::SharedFuture future);
};
