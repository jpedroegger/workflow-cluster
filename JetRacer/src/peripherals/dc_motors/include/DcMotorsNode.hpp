#pragma once

#include "APCA9685Driver.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>

#define MIN_COUNT 410  // 10% duty cycle
#define MAX_COUNT 3680 // 90% duty cycle
#define PCA_MOTORS_ADDRESS 0x60

/**
 * @class DcMotorsNode
 * @brief Listens to twist message and translate them into PWM signal values
 * that the pca driver understands.
 *
 */
class DcMotorsNode : public rclcpp::Node
{
    public:
        DcMotorsNode();
        ~DcMotorsNode();

        uint8_t
        initPCA9685(std::shared_ptr<APCA9685Driver> mock_driver = nullptr);

    private:
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr
            twist_subscriber_;
        std::shared_ptr<APCA9685Driver> pca_driver_;

        void writeSpeed(const geometry_msgs::msg::Twist::SharedPtr twist_msg);
};
