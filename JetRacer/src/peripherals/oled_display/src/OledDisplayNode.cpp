#include "OledDisplayNode.hpp"

using namespace std::chrono_literals;

OledDisplayNode::OledDisplayNode() : rclcpp::Node("oled_display")
{
    display_subscriber_ = this->create_subscription<custom_msgs::msg::Display>(
        "cmd_display", 10,
        std::bind(&OledDisplayNode::writeToI2c, this, std::placeholders::_1));
}

OledDisplayNode::~OledDisplayNode() {}

void OledDisplayNode::initSSD1306()
{
    ssd1306_ = std::make_unique<SSD1306Driver>(shared_from_this());
    if (ssd1306_->initDisplay() != EXIT_SUCCESS ||
        ssd1306_->setDefaultConfig() != EXIT_SUCCESS)
        return;
    ssd1306_->onOffDisplay(0);
    ssd1306_->clearScreen();
    ssd1306_->rotateDisplay(0);
}

/**
 * @brief request to the i2c service a write operation via the driver upon
 * receiving a message in the display_topic
 *
 * @param msg
 */
void OledDisplayNode::writeToI2c(const custom_msgs::msg::Display::SharedPtr msg)
{
    ssd1306_->clearScreen();

    if (ssd1306_->setCursor(2, 0))
        return;
    if (ssd1306_->writeString(SSD1306_FONT_NORMAL, msg->line1))
        return;
    if (ssd1306_->setCursor(2, 1))
        return;
    if (ssd1306_->writeString(SSD1306_FONT_NORMAL, msg->line2))
        return;
    if (ssd1306_->setCursor(2, 2))
        return;
    if (ssd1306_->writeString(SSD1306_FONT_NORMAL, msg->line3))
        return;
    if (ssd1306_->setCursor(2, 3))
        return;
    if (ssd1306_->writeString(SSD1306_FONT_NORMAL, msg->line4))
        return;
}
