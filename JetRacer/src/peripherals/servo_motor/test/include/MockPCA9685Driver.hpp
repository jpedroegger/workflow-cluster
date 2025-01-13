#pragma once
#include "APCA9685Driver.hpp"
#include <gmock/gmock.h>

class MockPCA9685Driver : public APCA9685Driver
{
    public:
        MOCK_METHOD(void, setRegister, (uint8_t reg, uint8_t value),
                    (override));
        MOCK_METHOD(void, setPWMFrequency, (float freq_Hz), (override));
        MOCK_METHOD(void, setPWMDutyCycle,
                    (uint8_t channel, uint16_t on, uint16_t off), (override));
        MOCK_METHOD(void, setGPIO, (uint8_t channel, bool on), (override));
};
