#pragma once

#include <DcMotorsNode.hpp>
#include <MockPCA9685Driver.hpp>
#include <geometry_msgs/msg/twist.h>
#include <gmock/gmock.h>
#include <thread>

using namespace testing;

class DcMotorsNodeTest : public TestWithParam<float>
{
    protected:
        void SetUp() override;
        void TearDown() override;

        std::shared_ptr<DcMotorsNode> test_node_;
        std::shared_ptr<MockPCA9685Driver> mock_driver_;
        std::shared_ptr<rclcpp::Publisher<geometry_msgs::msg::Twist>>
            cmd_vel_pub_;
        std::unique_ptr<rclcpp::executors::SingleThreadedExecutor> executor_;
        std::thread executor_thread_;
};
