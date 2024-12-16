#include <BatteryNode.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>

using namespace std::chrono_literals;

BatteryNode::BatteryNode() : Node("battery_node")
{
    timer_ = this->create_timer(
        5s, std::bind(&BatteryNode::publishBatteryLevel, this));
}

void BatteryNode::initINA219()
{
    ina219_driver_ = std::make_shared<INA219Driver>(this->shared_from_this(),
                                                    INA219_ADDRESS);
}

void BatteryNode::publishBatteryLevel() { ina219_driver_->publishBusVoltage(); }
