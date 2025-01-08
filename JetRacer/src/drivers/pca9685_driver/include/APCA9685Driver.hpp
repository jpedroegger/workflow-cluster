#pragma once

#include <rclcpp/rclcpp.hpp>

class APCA9685Driver
{
    public:
        APCA9685Driver() = default;
        virtual ~APCA9685Driver() = default;

        virtual void setRegister(uint8_t reg, uint8_t value) = 0;
        virtual void setPWMFrequency(float freq_Hz) = 0;
        virtual void setPWMDutyCycle(uint8_t channel, uint16_t on,
                                     uint16_t off) = 0;
        virtual void setGPIO(uint8_t channel, bool on) = 0;
};
