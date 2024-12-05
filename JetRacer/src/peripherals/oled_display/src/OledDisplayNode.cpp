#include "OledDisplayNode.hpp"
#include "font.hpp"
#include "ssd1306.hpp"
#include <cstdlib>

using namespace std::chrono_literals;

OledDisplayNode::OledDisplayNode() : rclcpp::Node("oled_display")
{
    i2c_client_ =
        this->create_client<custom_msgs::srv::I2cService>("i2c_service");

    display_subscriber_ = this->create_subscription<std_msgs::msg::String>(
        "cmd_display", 10,
        std::bind(&OledDisplayNode::writeToI2c, this, std::placeholders::_1));

    while (!i2c_client_->wait_for_service(2s))
        RCLCPP_INFO(this->get_logger(), "Waiting for i2c service to start");

    if (initDisplay() != EXIT_SUCCESS || setDefaultConfig() != EXIT_SUCCESS)
        return;
    clearScreen();
    RCLCPP_INFO(this->get_logger(), "Starting oled display");
}

OledDisplayNode::~OledDisplayNode() {}

/**
 * @brief request to the i2c service a write operation upon receiving a message
 * in the display_topic
 *
 * @param msg
 */
void OledDisplayNode::writeToI2c(const std_msgs::msg::String::SharedPtr msg)
{
    current_page++;
    if (current_page == 4)
    {
        current_page = 0;
        if (clearScreen())
            return;
    }

    if (setCursor(2, current_page))
        return;
    if (writeString(SSD1306_FONT_NORMAL, msg->data))
        return;
}

/**
 * @brief wait for the response of the i2c service by blocking since the
 * sequence of writes to the screen is important. this function can not be
 * called in a call back since its blocking. If so rclcpp runtime throw an
 * exception
 *
 * @param future
 * @param operation
 * @return
 */
// int OledDisplayNode::waitForResponse(
//     rclcpp::Client<custom_msgs::srv::I2cService>::SharedFuture future,
//     const std::string& operation)
// {
//     // TODO: try while !future.valid()
//     //  Wait for the future to be ready or timeout
//     auto status = rclcpp::spin_until_future_complete(
//         this->get_node_base_interface(), future);
//     RCLCPP_DEBUG(this->get_logger(), "status: %d", static_cast<int>(status));
//     if (status == rclcpp::FutureReturnCode::SUCCESS)
//     {
//         // Extract the response
//         auto response = future.get();
//         if (!response->success)
//         {
//             RCLCPP_ERROR(this->get_logger(), "FAILURE: %s: %s",
//                          operation.c_str(), response->message.c_str());
//             return EXIT_FAILURE;
//         }
//         RCLCPP_DEBUG(this->get_logger(), "SUCCESS: %s", operation.c_str());
//         return EXIT_SUCCESS;
//     }
//     else
//     {
//         RCLCPP_ERROR(this->get_logger(), "TIMEOUT or UNKNOWN ERROR: %s",
//                      operation.c_str());
//         return EXIT_FAILURE;
//     }
// }

// DISPLAY INTERFACE
// When requesting to the i2c interface, we either block until receiving a
// response (for critical operation like init the display) or we can handle the
// response asynchronously to avoid blocking the thread.

/*custom_msgs
 * @brief try to read and write dummy bytes to the display.
 *
 * @return
 */
int OledDisplayNode::initDisplay()
{
    auto write_request =
        std::make_shared<custom_msgs::srv::I2cService::Request>();
    auto read_request =
        std::make_shared<custom_msgs::srv::I2cService::Request>();

    write_request->set__read_request(false);
    write_request->set__device_address(SSD1306_I2C_ADDR);
    write_request->write_data.push_back(SSD1306_COMM_CONTROL_BYTE);

    read_request->set__read_request(true);
    read_request->set__device_address(SSD1306_I2C_ADDR);
    read_request->set__read_length(1);

    i2c_client_->async_send_request(
        write_request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                                 std::placeholders::_1));
    i2c_client_->async_send_request(
        read_request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                                std::placeholders::_1));
    // // Try to write and read.
    // int write_result = waitForResponse(future_write, "Init display write");
    // int read_result = waitForResponse(future_read, "Init display read");

    // return write_result == EXIT_SUCCESS && read_result == EXIT_SUCCESS
    //            ? EXIT_SUCCESS
    //            : EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void OledDisplayNode::asyncI2cResponse(
    rclcpp::Client<custom_msgs::srv::I2cService>::SharedFuture future)
{
    auto response = future.get();
    if (!response->success)
        RCLCPP_ERROR(this->get_logger(), "FAILURE: %s",
                     response->message.c_str());
    else
        RCLCPP_DEBUG(this->get_logger(), "SUCCESS");
}

int OledDisplayNode::onOffDisplay(uint8_t onoff)
{
    auto request = std::make_shared<custom_msgs::srv::I2cService::Request>();

    request->set__read_request(false);
    request->set__device_address(SSD1306_I2C_ADDR);
    request->write_data.push_back(SSD1306_COMM_CONTROL_BYTE);
    if (!onoff)
        request->write_data.push_back(SSD1306_COMM_DISPLAY_ON);
    else
        request->write_data.push_back(SSD1306_COMM_DISPLAY_OFF);

    i2c_client_->async_send_request(
        request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                           std::placeholders::_1));
    return EXIT_SUCCESS;
}

int OledDisplayNode::setDefaultConfig()
{
    auto request = std::make_shared<custom_msgs::srv::I2cService::Request>();

    request->set__read_request(false);
    request->set__device_address(SSD1306_I2C_ADDR);

    request->write_data.push_back(SSD1306_COMM_CONTROL_BYTE); // ctrl byte
    request->write_data.push_back(SSD1306_COMM_DISPLAY_OFF);  // display on
    request->write_data.push_back(SSD1306_COMM_DISP_NORM);    // normal display
    request->write_data.push_back(SSD1306_COMM_CLK_SET);      // set clock div
    request->write_data.push_back(SSD1306_SCREEN_RATIO);      // ratio 0x80
    request->write_data.push_back(SSD1306_COMM_MULTIPLEX);    // set multiplex
    request->write_data.push_back(SSD1306_HEIGHT - 1);
    request->write_data.push_back(SSD1306_COMM_VERT_OFFSET); // offset
    request->write_data.push_back(0); // no horizontal offset
    request->write_data.push_back(SSD1306_COMM_START_LINE);
    request->write_data.push_back(SSD1306_COMM_CHARGE_PUMP);
    request->write_data.push_back(0x14); // turn on charge pump
    request->write_data.push_back(SSD1306_COMM_MEMORY_MODE);
    request->write_data.push_back(SSD1306_PAGE_MODE);
    request->write_data.push_back(SSD1306_COMM_HORIZ_NORM);
    request->write_data.push_back(SSD1306_COMM_SCAN_NORM);
    request->write_data.push_back(SSD1306_COMM_COM_PIN);
    request->write_data.push_back(0x02); // for display with 32 lines
    request->write_data.push_back(SSD1306_COMM_CONTRAST);
    request->write_data.push_back(0x7f); // default contrast value
    request->write_data.push_back(SSD1306_COMM_PRECHARGE);
    request->write_data.push_back(0xf1); // default precharge value
    request->write_data.push_back(SSD1306_COMM_DESELECT_LV);
    request->write_data.push_back(0x40); // default deselct val
    request->write_data.push_back(SSD1306_COMM_RESUME_RAM);
    request->write_data.push_back(SSD1306_COMM_DISP_NORM);
    request->write_data.push_back(SSD1306_COMM_DISPLAY_ON);
    request->write_data.push_back(SSD1306_COMM_DISABLE_SCROLL);

    i2c_client_->async_send_request(
        request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                           std::placeholders::_1));
    return EXIT_SUCCESS;
}

int OledDisplayNode::setCursor(uint8_t x, uint8_t y)
{
    if (x >= SSD1306_WIDTH || y >= (SSD1306_HEIGHT / 8))
    {
        RCLCPP_ERROR(this->get_logger(), "setting cursor");
        return EXIT_FAILURE;
    }

    auto request = std::make_shared<custom_msgs::srv::I2cService::Request>();

    request->set__read_request(false);
    request->set__device_address(SSD1306_I2C_ADDR);
    request->write_data.push_back(SSD1306_COMM_CONTROL_BYTE);
    request->write_data.push_back(SSD1306_COMM_PAGE_NUMBER | (y & 0x0f));
    request->write_data.push_back(SSD1306_COMM_LOW_COLUMN | (x & 0x0f));
    request->write_data.push_back(SSD1306_COMM_HIGH_COLUMN | ((x >> 4) & 0x0f));

    i2c_client_->async_send_request(
        request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                           std::placeholders::_1));
    return EXIT_SUCCESS;
}

int OledDisplayNode::clearRow(uint8_t row)
{
    if (row >= (SSD1306_HEIGHT / 8))
    {
        RCLCPP_ERROR(this->get_logger(), "invalid row number");
        return EXIT_FAILURE;
    }

    auto request = std::make_shared<custom_msgs::srv::I2cService::Request>();

    setCursor(0, row);
    request->set__read_request(false);
    request->set__device_address(SSD1306_I2C_ADDR);

    request->write_data.push_back(SSD1306_DATA_CONTROL_BYTE);
    for (uint8_t i = 0; i < SSD1306_WIDTH; i++)
        request->write_data.push_back(0x00);

    i2c_client_->async_send_request(
        request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                           std::placeholders::_1));
    return EXIT_SUCCESS;
}

int OledDisplayNode::clearScreen()
{
    int result = 0;

    for (uint8_t i = 0; i < (SSD1306_HEIGHT / 8); i++)
        result += clearRow(i);
    return result;
}

int OledDisplayNode::writeString(uint8_t size, const std::string& msg)
{
    uint8_t* font_table = 0;
    uint8_t font_table_width = 0;

    if (size == SSD1306_FONT_SMALL)
    {
        font_table = (uint8_t*)font5x7;
        font_table_width = 5;
    }
    else if (size == SSD1306_FONT_NORMAL)
    {
        font_table = (uint8_t*)font8x8;
        font_table_width = 8;

        auto request =
            std::make_shared<custom_msgs::srv::I2cService::Request>();

        request->set__read_request(false);
        request->set__device_address(SSD1306_I2C_ADDR);
        request->write_data.push_back(SSD1306_DATA_CONTROL_BYTE);

        // font table range in ascii table is from 0x20(space) to 0x7e(~)
        for (char c : msg)
        {
            if (c < ' ' || c > '~')
                return EXIT_FAILURE;

            uint8_t* font_ptr = &font_table[(c - 0x20) * font_table_width];
            uint8_t j = 0;
            for (j = 0; j < font_table_width; j++)
                request->write_data.push_back(font_ptr[j]);

            if (size == SSD1306_FONT_SMALL)
                request->write_data.push_back(0x00);
        }

        i2c_client_->async_send_request(
            request, std::bind(&OledDisplayNode::asyncI2cResponse, this,
                               std::placeholders::_1));
    }
    return EXIT_SUCCESS;
}
