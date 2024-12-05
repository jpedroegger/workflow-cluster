#include "OledDisplayNode.hpp"
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OledDisplayNode>());
    rclcpp::shutdown();
    return EXIT_SUCCESS;
}
