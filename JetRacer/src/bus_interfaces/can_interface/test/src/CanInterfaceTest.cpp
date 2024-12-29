#include "CanInterfaceTest.hpp"

void CanInterfaceTest::SetUp()
{
    rclcpp::init(0, nullptr);

    mock_driver_ = std::make_shared<MockCanDriver>();
    test_node_ = std::make_shared<CanInterface>(mock_driver_);
    can_client_ =
        test_node_->create_client<custom_msgs::srv::CanService>("can_service");
    executor_ = rclcpp::executors::SingleThreadedExecutor::make_unique();
    executor_->add_node(test_node_);

    executor_thread_ = std::thread([this]() { executor_->spin(); });
}

void CanInterfaceTest::TearDown()
{
    executor_->cancel();
    if (executor_thread_.joinable())
        executor_thread_.join();
    rclcpp::shutdown();
}

TEST_F(CanInterfaceTest, readMessage)
{
    EXPECT_CALL(*mock_driver_, waitForMessages)
        .WillOnce(::testing::Return(true));
    EXPECT_CALL(*mock_driver_, readMessage)
        .WillOnce(
            []()
            {
                const sockcanpp::CanId id(0x10);
                sockcanpp::CanMessage msg(id, "hey");

                return msg;
            });

    auto request = std::make_shared<custom_msgs::srv::CanService::Request>();
    request->read_request = true;
    request->read_length = 3;

    auto future = can_client_->async_send_request(request);
    auto response = future.get();

    EXPECT_EQ(response->success, true);
    EXPECT_EQ(response->read_data.at(0), 'h');
}
