#pragma once
#include "CanDriver.hpp"
#include "ICanDriver.hpp"

/**
 * @class RCanDriver
 * @brief Concrete implementation of the abstract interface.
 *
 * This class essentially wraps the call to sockcancpp::CanDriver methods
 * (adaptor).
 *
 */
class RCanDriver : public ICanDriver
{
    private:
        std::unique_ptr<sockcanpp::CanDriver> driver_;

    public:
        RCanDriver(const std::string& name, int can_mode);
        ssize_t sendMessage(const sockcanpp::CanMessage& msg,
                            bool force_extended = false) override;
        sockcanpp::CanMessage readMessage() override;
        bool waitForMessages(sockcanpp::milliseconds timeout) override;
};
