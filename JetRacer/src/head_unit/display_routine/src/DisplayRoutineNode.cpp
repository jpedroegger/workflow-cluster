#include "DisplayRoutineNode.hpp"
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <netinet/in.h>

using namespace std::chrono_literals;

DisplayRoutineNode::DisplayRoutineNode() : rclcpp::Node("display_routine_node")
{
    timer_ = this->create_timer(
        10s, std::bind(&DisplayRoutineNode::updateDisplay, this));
    publisher_ =
        this->create_publisher<std_msgs::msg::String>("cmd_display", 10);

    auto addresses = getIPv4Addresses();
    if (!addresses.empty())
        ip_address_ = addresses.at(0);
}

void DisplayRoutineNode::updateDisplay() const
{
    std_msgs::msg::String::SharedPtr msg =
        std::make_shared<std_msgs::msg::String>();

    msg->data = ip_address_;
}

std::vector<std::string> DisplayRoutineNode::getIPv4Addresses() const
{
    std::vector<std::string> ipAddresses;

    struct ifaddrs* ifaddr;
    if (getifaddrs(&ifaddr) == -1)
    {
        RCLCPP_ERROR(this->get_logger(), "Fail to get network interfaces: %s",
                     std::string(std::strerror(errno)).c_str());
    }

    // Use a smart pointer to automatically free the linked list
    std::unique_ptr<struct ifaddrs, decltype(&freeifaddrs)> ifaddr_guard(
        ifaddr, freeifaddrs);

    // Iterate through the linked list of interfaces
    for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == nullptr)
        {
            continue;
        }

        // Only consider IPv4 addresses
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            struct sockaddr_in* ipv4 =
                reinterpret_cast<struct sockaddr_in*>(ifa->ifa_addr);
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &ipv4->sin_addr, ip, INET_ADDRSTRLEN);

            if (std::string(ip) != "127.0.0.1")
                ipAddresses.emplace_back(ip);
        }
    }

    return ipAddresses;
}
