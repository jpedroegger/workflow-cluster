#pragma once

#include <INA219Driver.hpp>
#include <INA219def.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <std_msgs/msg/u_int8.hpp>

/**
 * @class BatteryNode
 * @brief request battery readings every 5 seconds and publishes it via the
 * INA219 driver.
 *
 */
class BatteryNode : public rclcpp::Node
{
    public:
        BatteryNode();
        ~BatteryNode() = default;

        uint8_t initINA219();
        void publishBatteryLevel();

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        std::shared_ptr<INA219Driver> ina219_driver_;
};
