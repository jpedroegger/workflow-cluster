#include "PCA9685Driver.hpp"
#include <custom_msgs/srv/i2c_service.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include <thread>

using ::testing::_;
using ::testing::InSequence;

/**
 * @class MockI2cService
 * @brief mocks the request handling.
 *
 * The idea is to intercept the request and examine its content to see if the
 * driver works as expected. To do so we will spin a node providing a mock
 * service that we can control the behaviour of.
 *
 */
class MockI2cService
{
    public:
        MOCK_METHOD(void, HandleRequest,
                    (const custom_msgs::srv::I2cService_Request&,
                     custom_msgs::srv::I2cService_Response&));
};

class MockI2cServiceNode : public rclcpp::Node
{
    public:
        MockI2cServiceNode() : Node("mock_i2c_service")
        {
            i2c_service_ = create_service<custom_msgs::srv::I2cService>(
                "i2c_service",
                [this](
                    const std::shared_ptr<custom_msgs::srv::I2cService_Request>
                        request,
                    const std::shared_ptr<custom_msgs::srv::I2cService_Response>
                        response)
                { mock_service_.HandleRequest(*request, *response); });
        };

        MockI2cService& getMockService() { return mock_service_; }

    private:
        rclcpp::Service<custom_msgs::srv::I2cService>::SharedPtr i2c_service_;
        MockI2cService mock_service_;
};

class PCA9685DriverTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            rclcpp::init(0, nullptr);
            test_node_ = std::make_shared<rclcpp::Node>("test_node");
            mock_i2c_node_ = std::make_shared<MockI2cServiceNode>();

            executor_ =
                std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
            executor_->add_node(mock_i2c_node_);
            executor_thread_ = std::thread([this]() { executor_->spin(); });
        }

        void TearDown() override
        {
            executor_->cancel();
            if (executor_thread_.joinable())
                executor_thread_.join();
            rclcpp::shutdown();
        }

        std::shared_ptr<rclcpp::Node> test_node_;
        std::shared_ptr<MockI2cServiceNode> mock_i2c_node_;
        std::shared_ptr<rclcpp::executors::SingleThreadedExecutor> executor_;
        std::thread executor_thread_;
};

TEST_F(PCA9685DriverTest, TestPingFailure)
{
    EXPECT_CALL(mock_i2c_node_->getMockService(), HandleRequest)
        .WillOnce([]() {});
}

TEST_F(PCA9685DriverTest, TestSetPWMFrequency)
{
    InSequence seq; // Enforce ordering of expectations
    float frequency = 50.0;

    // First expect the ping() call from constructor
    EXPECT_CALL(mock_i2c_node_->getMockService(), HandleRequest)
        .WillOnce(
            [](const auto& req, auto& resp)
            {
                EXPECT_EQ(req.device_address, 0x40);
                EXPECT_EQ(req.write_data[0], 0x00);
                resp.success = true;
            });

    // // Then expect the setPWMFrequency sequence
    EXPECT_CALL(mock_i2c_node_->getMockService(), HandleRequest)
        .WillOnce(
            [](const auto& req, auto& resp)
            {
                EXPECT_EQ(req.device_address, 0x40);
                EXPECT_EQ(req.write_data[0], MODE1_REGISTER);
                EXPECT_EQ(req.write_data[1], 0x10); // Sleep mode
                resp.success = true;
            });

    EXPECT_CALL(mock_i2c_node_->getMockService(), HandleRequest)
        .WillOnce(
            [frequency](const auto& req, auto& resp)
            {
                EXPECT_EQ(req.device_address, 0x40);
                EXPECT_EQ(req.write_data[0], PRESCALE_REGISTER);
                // Calculate expected prescale for 50Hz
                uint8_t expected_prescale = static_cast<uint8_t>(
                    (25000000.0 / (4096 * frequency)) - 1.0);
                EXPECT_EQ(req.write_data[1], expected_prescale);
                resp.success = true;
            });

    EXPECT_CALL(mock_i2c_node_->getMockService(), HandleRequest)
        .WillOnce(
            [](const auto& req, auto& resp)
            {
                EXPECT_EQ(req.device_address, 0x40);
                EXPECT_EQ(req.write_data[0], MODE1_REGISTER);
                EXPECT_EQ(req.write_data[1], 0x80); // Wake-up + auto
                resp.success = true;
            });

    // Create driver (this will call ping())
    PCA9685Driver driver(test_node_, 0x40);

    // Then set frequency
    driver.setPWMFrequency(frequency);
}
