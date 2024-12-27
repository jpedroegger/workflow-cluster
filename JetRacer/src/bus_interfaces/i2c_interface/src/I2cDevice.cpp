#include <I2cDevice.hpp>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

I2cDevice::I2cDevice(uint8_t device) : AI2cDevice(device) {}

I2cDevice::~I2cDevice()
{
    if (i2c_fd_ > 0)
        ::close(i2c_fd_);
}
int I2cDevice::open()
{
    std::string i2c_device_name = "/dev/i2c-" + std::to_string(device_);
    i2c_fd_ = ::open(i2c_device_name.c_str(), O_RDWR);
    return i2c_fd_;
}

ssize_t I2cDevice::read(std::vector<uint8_t>& buff)
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

ssize_t I2cDevice::write(std::vector<uint8_t>& buff)
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

int I2cDevice::setAddress(uint8_t address)
{
    return ::ioctl(i2c_fd_, I2C_SLAVE, address);
}
