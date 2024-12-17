#include <custom_msgs/msg/display.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/u_int8.hpp>

using namespace std::chrono_literals;

class TesterNode : public rclcpp::Node
{
    public:
        TesterNode() : Node("tester_node")
        {
            // Custom QoS profile for low latency and reliable delivery
            rclcpp::QoS qos_profile = rclcpp::QoS(rclcpp::KeepLast(10))
                                          .reliable()
                                          .durability_volatile();

            timer_servo = this->create_timer(
                1s, std::bind(&TesterNode::servoCallback, this));
            timer_dc_motors = this->create_timer(
                1s, std::bind(&TesterNode::dcMotorsCallback, this));
            timer_display = this->create_timer(
                1s, std::bind(&TesterNode::displayCallback, this));

            direction_publisher_ = this->create_publisher<std_msgs::msg::UInt8>(
                "cmd_direction", qos_profile);
            speed_publisher_ = this->create_publisher<std_msgs::msg::UInt8>(
                "cmd_speed", qos_profile);
            display_publisher_ =
                this->create_publisher<custom_msgs::msg::Display>("cmd_display",
                                                                  qos_profile);

            RCLCPP_INFO(this->get_logger(), "starting test all peripherals");
        }

    private:
        rclcpp::TimerBase::SharedPtr timer_display;
        rclcpp::TimerBase::SharedPtr timer_servo;
        rclcpp::TimerBase::SharedPtr timer_dc_motors;

        uint8_t speed = 0;
        uint8_t direction = 0;

        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr direction_publisher_;
        rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr speed_publisher_;
        rclcpp::Publisher<custom_msgs::msg::Display>::SharedPtr
            display_publisher_;

        void displayCallback()
        {
            auto msg = custom_msgs::msg::Display();

            msg.line1 = "Hello world";
            msg.line2 = "this is a test";
            msg.line3 = "test";
            msg.line4 = "test";
            display_publisher_->publish(msg);
        }

        void dcMotorsCallback()
        {
            auto msg = std_msgs::msg::UInt8();

            if (speed == 100)
                speed = 0;

            msg.data = speed;
            speed_publisher_->publish(msg);
            speed += 10;
        }

        void servoCallback()
        {
            auto msg = std_msgs::msg::UInt8();

            if (direction == 180)
                direction = 0;

            msg.data = direction;
            direction_publisher_->publish(msg);
            direction += 10;
        }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TesterNode>());
    rclcpp::shutdown();
    return 0;
}
