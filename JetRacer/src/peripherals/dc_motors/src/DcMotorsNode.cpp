#include "DcMotorsNode.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <functional>
#include <rclcpp/client.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>

using namespace std::chrono_literals;

DcMotorsNode::DcMotorsNode() : Node("dc_motors_node")
{
    speed_subscriber_ = this->create_subscription<std_msgs::msg::UInt8>(
        "cmd_speed", 10,
        std::bind(&DcMotorsNode::writeSpeed, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Starting the dc motors node");
}

DcMotorsNode::~DcMotorsNode() {}

void DcMotorsNode::initPCA9685()
{
    pca9685_ =
        std::make_shared<PCA9685Driver>(shared_from_this(), PCA_MOTORS_ADDRESS);
    pca9685_->setPWMFrequency(1600);
}

/**
 * @brief map speed in percentage to the appropriate duty cycle.
 *
 * freq = 1600;
 * 1 cycle = 1 /1600 = 625us
 * 625/4096 = 0.1526us per tick
 *
 * @param speed
 */
void DcMotorsNode::writeSpeed(const std_msgs::msg::UInt8::SharedPtr speed)
{
    if (speed->data > 100)
    {
        RCLCPP_ERROR(this->get_logger(),
                     "Invalid speed: %d (must be between 0 and 100 %%)",
                     speed->data);
        return;
    }

    // Map the angle speed in % to PCA9685 pulse width
    uint16_t pulseWidth =
        static_cast<uint16_t>((speed->data * (MAX_COUNT - MIN_COUNT)) / 100);

    pca9685_->setPWMDutyCycle(DEFAULT_CHANNEL, 0, pulseWidth);
    pca9685_->setGPIO(1, false);
    pca9685_->setGPIO(2, true);

    pca9685_->setPWMDutyCycle(7, 0, pulseWidth);
    pca9685_->setGPIO(6, false);
    pca9685_->setGPIO(5, true);
}
