#include "CanInterface.hpp"
#include "CanMessage.hpp"
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
        "can_service",
        std::bind(&CanInterface::handleCanRequest, this, std::placeholders::_1,
                  std::placeholders::_2),
        qos);
    publisher_ =
        this->create_publisher<custom_msgs::msg::CanFrame>("raw_CAN", 10);

    RCLCPP_INFO(this->get_logger(), "Starting CAN bus interface");
}

CanInterface::~CanInterface()
{
    if (polling_thread_.joinable())
        polling_thread_.join();
}

/**
 * @brief function beeing called upon a request to the can service.
 *
 * the struct of the can service allows writting and reading operation. To see
 * the service definition do "ros2 interface show custom_msgs/srv/CanService" or
 * see JetRacer/src/bus_interfaces/custom_msgs/srv/CanService.
 *
 *
 * @param request
 * @param response
 */
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
        auto data = request->write_data;
        for (size_t i = 0; i < frame.can_dlc; i++)
            frame.data[i] = data[0];

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
            return;
        }

        CanMessage received_msg = can_driver_->readMessage();
        auto frame_data = received_msg.getFrameData();

        // Resize the response read_data to match the size of frame_data
        response->read_data.resize(frame_data.size());
        std::copy(frame_data.begin(), frame_data.end(),
                  response->read_data.begin());
    }
    response->set__message("success");
}
