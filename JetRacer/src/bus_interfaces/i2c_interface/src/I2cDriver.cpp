#include <I2cDriver.hpp>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

I2cDriver::I2cDriver(uint8_t device) : II2cDriver(device) {}

I2cDriver::~I2cDriver()
{
    if (i2c_fd_ > 0)
        ::close(i2c_fd_);
}

/**
 * @brief Opens the I2C device file for communication.
 *
 * Constructs the device file path based on the device ID and opens it
 * in read/write mode.
 *
 * @return The file descriptor of the opened I2C device, or a negative
 * value if the operation fails.
 */
int I2cDriver::open()
{
    std::string i2c_device_name = "/dev/i2c-" + std::to_string(device_);
    i2c_fd_ = ::open(i2c_device_name.c_str(), O_RDWR);
    return i2c_fd_;
}

/**
 * @brief Reads data from the I2C device.
 *
 * Attempts to read a specified number of bytes from the I2C device into
 * the provided buffer. Retries the operation up to MAX_RETRY times if
 * necessary.
 *
 * @param buff A reference to the buffer where the read data will be stored.
 * @return The total number of bytes read, or a negative value if the
 * operation fails.
 */

ssize_t I2cDriver::read(std::vector<uint8_t>& buff)
{
    int bytes_read = 0;
    int total_read = 0;
    int retries = 0;

    while (total_read < buff.size() && retries < MAX_RETRY)
    {
        bytes_read =
            ::read(i2c_fd_, buff.data() + total_read, buff.size() - total_read);
        if (bytes_read < 0)
            return bytes_read;
        if (bytes_read == 0 && retries++ >= MAX_RETRY)
            break;
        total_read += bytes_read;
    }
    return total_read;
}

ssize_t I2cDriver::write(std::vector<uint8_t>& buff)
{
    int bytes_written = 0;
    int total_written = 0;
    int retries = 0;

    while (total_written < buff.size() && retries < MAX_RETRY)
    {
        bytes_written = ::write(i2c_fd_, buff.data() + total_written,
                                buff.size() - total_written);
        if (bytes_written < 0)
            return bytes_written;
        if (bytes_written == 0 && retries++ >= MAX_RETRY)
            break;
        total_written += bytes_written;
    }
    return total_written;
}

/**
 * @brief Sets the address of the I2C slave device.
 *
 * Configures the I2C device to communicate with a specific slave device
 * by setting the address.
 *
 * @param address The address of the I2C slave device.
 * @return 0 on success, or a negative value if the operation fails.
 */
int I2cDriver::setAddress(uint8_t address)
{
    return ::ioctl(i2c_fd_, I2C_SLAVE, address);
}
