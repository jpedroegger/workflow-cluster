#pragma once

#include "AI2cDevice.hpp"

const uint8_t MAX_RETRY = 5;

class I2cDevice : public AI2cDevice
{
    public:
        I2cDevice(uint8_t device);
        ~I2cDevice();

        int open() override;
        ssize_t read(std::vector<uint8_t>& buff) override;
        ssize_t write(std::vector<uint8_t>& buff) override;
        int setAddress(uint8_t address) override;
};
