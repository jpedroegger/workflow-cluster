#include "SpeedSensorNode.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include <rclcpp/logging.hpp>

SpeedSensorNode::SpeedSensorNode() : rclcpp::Node("speed_sensor")
{
    client_ = this->create_client<custom_msgs::srv::CanService>("can_service");
    timer_ = this->create_timer(std::chrono::milliseconds(POLL_FREQ_MS),
                                [this]() { readSpeed(); });
    speed_publisher_ =
        this->create_publisher<std_msgs::msg::UInt8>("speed_readings", 10);
    rpm_publisher_ =
        this->create_publisher<std_msgs::msg::UInt32>("rpm_readings", 10);
}

SpeedSensorNode::~SpeedSensorNode() {}

/**
 * @brief function called upon receiving a CAN_frame. reads the can_raw topic
 * and publishes the speed in a different topic
 *
 * @param future the future containing the response from the service
 */
void SpeedSensorNode::writeSpeed(
    rclcpp::Client<custom_msgs::srv::CanService>::SharedFuture future)
{
    auto response = future.get();
    if (!response->success)
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
    else
    {
        std_msgs::msg::UInt8 speed_msg;
        std_msgs::msg::UInt32 rpm_msg;
        float rot_per_sec =
            (static_cast<float>(response->read_data.at(0)) / NB_HOLES) *
            (1000.0 / POLL_FREQ_MS);
        float calculated_speed =
            (rot_per_sec * WHEELS_PERIMETER_M) * 10.0; // calculated speed dm/s

        rpm_msg.set__data(rot_per_sec * 60.0);
        speed_msg.set__data(calculated_speed);

        speed_publisher_->publish(speed_msg);
        rpm_publisher_->publish(rpm_msg);
    }
}

/**
 * @brief request a read operation on the bus
 *
 * the response should contain the data requested
 */
void SpeedSensorNode::readSpeed()
{
    auto request = std::make_shared<custom_msgs::srv::CanService::Request>();

    request->set__can_id(SPEED_SENSOR_ID);
    request->set__read_request(true);
    request->set__write_data(std::vector<uint8_t>{1});
    client_->async_send_request(
        request,
        [this](
            rclcpp::Client<custom_msgs::srv::CanService>::SharedFuture future)
        { writeSpeed(future); });
}
