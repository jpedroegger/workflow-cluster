#pragma once
#include "MockPCA9685Driver.hpp"
#include "ServoNode.hpp"
#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>

class ServoNodeTest
    : public ::testing::TestWithParam<std::tuple<double, uint8_t>>
{
    protected:
        void SetUp() override;
        void TearDown() override;

        std::shared_ptr<MockPCA9685Driver> mock_driver_;
        std::shared_ptr<ServoNode> test_node_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        std::unique_ptr<rclcpp::executors::SingleThreadedExecutor> executor_;
        std::thread executor_thread_;
};
