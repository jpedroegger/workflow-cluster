#include "I2cInterface.hpp"
#include "custom_msgs/srv/i2c_service.hpp"
#include <fcntl.h>
#include <fmt/core.h>
#include <linux/i2c-dev.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

I2cInterface::I2cInterface() : Node("i2c_interface")
{
    // Set up service with Reliable QoS
    rclcpp::QoS qos(rclcpp::KeepLast(60));
    qos.reliable();
    qos.durability_volatile();

    i2c_service_ = this->create_service<custom_msgs::srv::I2cService>(
        "i2c_service",
        std::bind(&I2cInterface::handleI2cRequest, this, std::placeholders::_1,
                  std::placeholders::_2),
        qos);
    init_();

    RCLCPP_INFO(this->get_logger(), "Starting i2c interface");
}

I2cInterface::~I2cInterface()
{
    if (i2c_fd_ > 0)
        close(i2c_fd_);
}

/**
 * @brief Open the /dev/i2c-1. this operation will fail if the user is not in
 * the i2c group ("sudo usermod -aG i2c $USER")
 */
void I2cInterface::init_()
{
    std::string i2c_dev = "/dev/i2c-1";

    i2c_fd_ = open(i2c_dev.c_str(), O_RDWR);
    if (i2c_fd_ < 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Fail opening %s", i2c_dev.c_str());
        throw std::runtime_error("Could not open i2c device");
    }
}

/**
 * @brief select a device on the bus by specifying its address
 *
 * @param address
 * @return
 */
int I2cInterface::setAddress_(uint8_t address)
{
    return ioctl(i2c_fd_, I2C_SLAVE, address);
}

/**
 * @brief write to the i2c bus.
 *
 * the function is designed to handle partial writes and to retry writting if
 * unsucceful
 *
 * @param data
 * @return
 */
int I2cInterface::write_(std::vector<uint8_t>& data)
{
    size_t total_written = 0;
    uint8_t retry = 0;

    while (total_written < data.size())
    {
        ssize_t bytes_written = write(i2c_fd_, data.data() + total_written,
                                      data.size() - total_written);
        if (bytes_written < 0 || retry >= MAX_RETRY)
            return -1;
        total_written += bytes_written;
        retry++;
    }
    return 0;
}

/**
 * @brief Read from i2c bus.
 *
 * The function is designed to handle partial reads
 *
 * @param length
 * @return
 */
std::vector<uint8_t> I2cInterface::read_(size_t length)
{
    std::vector<uint8_t> buffer(length);

    ssize_t bytes_read = read(i2c_fd_, buffer.data(), length);
    if (bytes_read < 0)
    {
        buffer.clear();
        return buffer;
    }
    if (static_cast<size_t>(bytes_read) < length)
    {
        RCLCPP_WARN(
            this->get_logger(),
            "Incomplete read operation, requested %zu but got %zd bytes",
            length, bytes_read);
        buffer.resize(bytes_read);
    }
    return buffer;
}

/**
 * @brief function beeing called upon a request to the i2c service.
 *
 * the struct of the i2c service allows writting and reading operation. To see
 * the service definition do "ros2 interface show custom_msgs/srv/I2cService" or
 * see JetRacer/src/bus_interfaces/custom_msgs/srv/I2cService.
 *
 * this node essentially write to the bus using the information passed in the
 * request and construct an appropriated response
 *
 * @param request
 * @param response
 */
void I2cInterface::handleI2cRequest(
    const std::shared_ptr<custom_msgs::srv::I2cService::Request> request,
    std::shared_ptr<custom_msgs::srv::I2cService::Response> response)
{
    response->set__success(true);

    if (setAddress_(request->device_address) != 0)
    {
        std::string error_msg =
            fmt::format("Fail to set the device at address 0x{:02X}",
                        request->device_address);
        RCLCPP_ERROR(this->get_logger(), "%s", error_msg.c_str());
        response->set__success(false);
        response->set__message(error_msg);
        return;
    }

    if (write_(request->write_data) != 0)
    {
        std::string error_msg = fmt::format("Fail to write to device 0x{:02X}",
                                            request->device_address);
        RCLCPP_ERROR(this->get_logger(), "%s", error_msg.c_str());
        response->set__success(false);
        response->set__message(error_msg);
        return;
    }
    RCLCPP_DEBUG(this->get_logger(), "Succefully writen at address 0x%02X",
                 request->device_address);

    if (request->read_request)
    {
        std::vector<uint8_t> data = read_(request->read_length);
        if (data.empty() && request->read_length > 0)
        {
            std::string error_msg = fmt::format(
                "Fail to read from device 0x{:02X}", request->device_address);
            RCLCPP_ERROR(this->get_logger(), "%s", error_msg.c_str());
            response->set__success(false);
            response->set__message(error_msg);
            return;
        }
        response->set__read_data(data);
    }
}
