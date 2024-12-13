#include "CanInterface.hpp"
#include "CanMessage.hpp"
#include <chrono>
#include <linux/can.h>
#include <memory>
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/utilities.hpp>
#include <thread>

using sockcanpp::CanMessage;
using namespace std::chrono_literals;

CanInterface::CanInterface() : Node("can_interface")
{
    rclcpp::QoS qos(40);
    qos.reliable();

    can_driver_ = std::make_shared<CanDriver>("can0", CAN_RAW);
    can_service_ = this->create_service<custom_msgs::srv::CanService>(
        "can_service", [this](const auto request, auto response)
        { handleCanRequest(request, response); }, qos);
    publisher_ =
        this->create_publisher<custom_msgs::msg::CanFrame>("raw_CAN", 10);
    polling_thread_ = std::thread(&CanInterface::pollCanBus, this);

    RCLCPP_INFO(this->get_logger(), "Starting CAN bus interface");
}

CanInterface::~CanInterface()
{
    if (polling_thread_.joinable())
        polling_thread_.join();
}

/**
 * @brief This function will simply pool the bus for new information and publish
 * it in a topic. so far this node only handle reading operations
 */
void CanInterface::pollCanBus()
{
    while (rclcpp::ok())
    {
        if (can_driver_->waitForMessages(std::chrono::milliseconds(10)))
        {
            custom_msgs::msg::CanFrame ros_msg;

            CanMessage received_msg = can_driver_->readMessage();
            ros_msg.set__id(received_msg.getCanId());
            ros_msg.set__data_len(received_msg.getFrameData().length());
            std::copy_n(received_msg.getFrameData().begin(), ros_msg.data_len,
                        ros_msg.data.begin());

            RCLCPP_DEBUG(this->get_logger(),
                         "Received CAN frame: ID=0x%X, LEN=%d", ros_msg.id,
                         ros_msg.data_len);

            publisher_->publish(ros_msg);
        }
    }
}

void CanInterface::handleCanRequest(
    const std::shared_ptr<custom_msgs::srv::CanService::Request> request,
    std::shared_ptr<custom_msgs::srv::CanService::Response> response)
{
    response->set__success(true);

    if (!request->write_data.empty())
    {
        can_frame frame;

        frame.can_id = request->can_id;
        frame.can_dlc = request->write_data.size();
        std::copy(request->write_data.begin(), request->write_data.end(),
                  frame.data);

        try
        {
            can_driver_->sendMessage(frame);
        }
        catch (const std::exception& e)
        {
            response->set__success(false);
            response->set__message(e.what());
            RCLCPP_ERROR(this->get_logger(), "Fail writing data: %s", e.what());
        }
    }

    if (request->read_request)
    {
        if (!can_driver_->waitForMessages(50ms))
        {
            response->set__success(false);
            response->set__message("request timedout");
            RCLCPP_ERROR(this->get_logger(),
                         "Fail reading can bus, request timed out");
        }

        CanMessage received_msg = can_driver_->readMessage();
        auto frame_data = received_msg.getFrameData();
        std::copy(frame_data.begin(), frame_data.end(), response->read_data);
    }
    response->set__message("success");
}
