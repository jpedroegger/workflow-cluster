#pragma once

#include <CanDriver.hpp>

/**
 * @class ICanDriver
 * @brief Abstract interface for Can operations
 *
 * This abstract class provides a hardware abstraction layer for can
 * communication, allowing for dependency injection and easier unit testing. By
 * implementing this interface, concrete classes can provide either real
 * hardware communication or mock implementations for testing.
 *
 * The interface wraps the essential can operations (read, write ..) into
 * virtual methods that can be overridden by concrete implementations.
 */
class ICanDriver
{
    public:
        virtual ~ICanDriver() = default;
        virtual ssize_t sendMessage(const sockcanpp::CanMessage& msg,
                                    bool force_extended = false) = 0;
        virtual sockcanpp::CanMessage readMessage() = 0;
        virtual bool waitForMessages(sockcanpp::milliseconds timeout) = 0;
};
