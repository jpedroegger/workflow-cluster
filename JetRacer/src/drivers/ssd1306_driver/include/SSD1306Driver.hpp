#pragma once

#include <cstdint>
#include <custom_msgs/msg/display.hpp>
#include <custom_msgs/srv/i2c_service.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class SSD1306Driver
{
    public:
        SSD1306Driver(std::shared_ptr<rclcpp::Node> node);
        ~SSD1306Driver();

        void asyncI2cResponse(
            rclcpp::Client<custom_msgs::srv::I2cService>::SharedFuture future);

        // display interface
        int initDisplay();
        int setDefaultConfig();
        int onOffDisplay(uint8_t onoff);
        int setCursor(uint8_t x, uint8_t y);
        int clearRow(uint8_t row);
        int clearScreen();
        int writeString(uint8_t size, const std::string& msg);
        int flipDisplay(uint8_t flip);
        int rotateDisplay(uint8_t degree);

    private:
        rclcpp::Node::SharedPtr node_;
        rclcpp::Client<custom_msgs::srv::I2cService>::SharedPtr i2c_client_;
};
