#include <I2cInterface.hpp>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto exec = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
    auto i2c_node = std::make_shared<I2cInterface>();
    exec->add_node(i2c_node);
    exec->spin();
    rclcpp::shutdown();

    return 0;
}
