#include "RCanDriver.hpp"

/**
 * @brief Constructs an RCanDriver object.
 *
 * Initializes the RCanDriver by creating a `sockcanpp::CanDriver` instance
 * with the specified interface name and CAN mode.
 *
 * @param name The name of the CAN interface (e.g., "can0").
 * @param can_mode The CAN operating mode to be used.
 */
RCanDriver::RCanDriver(const std::string& name, int can_mode)
    : driver_(std::make_unique<sockcanpp::CanDriver>(name, can_mode))
{
}

/**
 * @brief Sends a CAN message on the associated CAN bus.
 *
 * Transmits the given `sockcanpp::CanMessage` using the underlying
 * `sockcanpp::CanDriver`. An extended CAN ID can be forced if required.
 *
 * @param msg The CAN message to send.
 * @param force_extended Whether to force the use of an extended CAN ID.
 * @return ssize_t The number of bytes written to the CAN bus, or a negative
 * value if the operation fails.
 */
ssize_t RCanDriver::sendMessage(const sockcanpp::CanMessage& msg,
                                bool force_extended)
{
    return driver_->sendMessage(msg, force_extended);
}

/**
 * @brief Reads a CAN message from the associated CAN bus.
 *
 * Uses the underlying `sockcanpp::CanDriver` to retrieve a message from the CAN
 * bus.
 *
 * @return sockcanpp::CanMessage The CAN message read from the bus.
 */
sockcanpp::CanMessage RCanDriver::readMessage()
{
    return driver_->readMessage();
}

/**
 * @brief Waits for incoming CAN messages with a timeout.
 *
 * Blocks until at least one CAN message is available on the bus or until the
 * specified timeout elapses.
 *
 * @param timeout The maximum time (in milliseconds) to wait for messages.
 * @return true If one or more messages are available before the timeout.
 * @return false If the timeout elapses without any messages being available.
 */
bool RCanDriver::waitForMessages(sockcanpp::milliseconds timeout)
{
    return driver_->waitForMessages(timeout);
}
