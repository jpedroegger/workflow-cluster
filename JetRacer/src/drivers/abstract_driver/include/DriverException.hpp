#pragma once

#include <string>
/**
 * @class DriverException
 * @brief Exception class for driver errors
 *
 * This exception is thrown if the ping to the device fails.
 */
class DriverException : public std::exception
{
    private:
        std::string msg_;

    public:
        DriverException(const std::string& msg) : msg_(msg) {}
        const char* what() const noexcept override { return msg_.c_str(); }
};
