#include "CameraNode.hpp"
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CameraNode>();

    try
    {
        rclcpp::spin(node);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        rclcpp::shutdown();
    }
    return 0;
}
