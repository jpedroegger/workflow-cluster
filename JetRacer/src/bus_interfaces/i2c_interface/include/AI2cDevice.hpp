#pragma once

#include <cstdint>
#include <rclcpp/rclcpp.hpp>

class AI2cDevice
{
    public:
        AI2cDevice(uint8_t device) : device_(device){};
        virtual ~AI2cDevice() = default;

        virtual int open() = 0;
        virtual ssize_t read(std::vector<uint8_t>& buff) = 0;
        virtual ssize_t write(std::vector<uint8_t>& buff) = 0;
        virtual int setAddress(uint8_t address) = 0;

        uint8_t getDeviceNb() const { return device_; }

    protected:
        uint8_t device_;
        int i2c_fd_;
};
