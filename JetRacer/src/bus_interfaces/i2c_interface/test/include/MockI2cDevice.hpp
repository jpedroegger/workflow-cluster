#include "AI2cDevice.hpp"
#include <gmock/gmock.h>

class MockI2cDevice : public AI2cDevice
{
    public:
        MockI2cDevice(uint8_t device) : AI2cDevice(device){};
        MOCK_METHOD(int, open, (), (override));
        MOCK_METHOD(ssize_t, read, (std::vector<uint8_t> & buff), (override));
        MOCK_METHOD(ssize_t, write, (std::vector<uint8_t> & buff), (override));
        MOCK_METHOD(int, setAddress, (uint8_t address), (override));
};
