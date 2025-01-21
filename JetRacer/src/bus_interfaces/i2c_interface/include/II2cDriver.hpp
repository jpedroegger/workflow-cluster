#pragma once

#include <cstdint>
#include <rclcpp/rclcpp.hpp>

#pragma once
#include <cstdint>
#include <rclcpp/rclcpp.hpp>

/**
 * @class II2cDriver
 * @brief Abstract interface for I2C operations
 *
 * This abstract class provides a hardware abstraction layer for I2C
 * communication, allowing for dependency injection and easier unit testing. By
 * implementing this interface, concrete classes can provide either real
 * hardware communication or mock implementations for testing.
 *
 * The interface wraps the essential I2C operations (open, read, write, and
 * address setting) into virtual methods that can be overridden by concrete
 * implementations. See I2cDriver for more information about its methods.
 */
class II2cDriver
{
    public:
        II2cDriver(uint8_t device) : device_(device){};
        virtual ~II2cDriver() = default;

        virtual int open() = 0;
        virtual ssize_t read(std::vector<uint8_t>& buff) = 0;
        virtual ssize_t write(std::vector<uint8_t>& buff) = 0;
        virtual int setAddress(uint8_t address) = 0;
        uint8_t getDeviceNb() const { return device_; }

    protected:
        uint8_t device_;
        int i2c_fd_;
};
