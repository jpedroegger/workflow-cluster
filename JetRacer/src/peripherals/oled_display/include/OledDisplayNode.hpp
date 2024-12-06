#pragma once

#include <cstdint>
#include <custom_msgs/srv/i2c_service.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class OledDisplayNode : public rclcpp::Node
{
    public:
        OledDisplayNode();
        ~OledDisplayNode();

    private:
        rclcpp::Client<custom_msgs::srv::I2cService>::SharedPtr i2c_client_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr
            display_subscriber_;

        void writeToI2c(const std_msgs::msg::String::SharedPtr msg);
        int waitForResponse(
            rclcpp::Client<custom_msgs::srv::I2cService>::SharedFuture future,
            const std::string& operation);
        void asyncI2cResponse(
            rclcpp::Client<custom_msgs::srv::I2cService>::SharedFuture future);
        int current_page = -1;

        // display interface
        int initDisplay();
        int setDefaultConfig();
        int onOffDisplay(uint8_t onoff);
        int setCursor(uint8_t x, uint8_t y);
        int clearRow(uint8_t row);
        int clearScreen();
        int writeString(uint8_t size, const std::string& msg);
};
