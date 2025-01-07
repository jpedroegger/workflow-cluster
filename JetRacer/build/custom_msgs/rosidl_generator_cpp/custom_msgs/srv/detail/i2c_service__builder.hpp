// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:srv/I2cService.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/srv/i2c_service.hpp"


#ifndef CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__BUILDER_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/srv/detail/i2c_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_I2cService_Request_read_length
{
public:
  explicit Init_I2cService_Request_read_length(::custom_msgs::srv::I2cService_Request & msg)
  : msg_(msg)
  {}
  ::custom_msgs::srv::I2cService_Request read_length(::custom_msgs::srv::I2cService_Request::_read_length_type arg)
  {
    msg_.read_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Request msg_;
};

class Init_I2cService_Request_read_request
{
public:
  explicit Init_I2cService_Request_read_request(::custom_msgs::srv::I2cService_Request & msg)
  : msg_(msg)
  {}
  Init_I2cService_Request_read_length read_request(::custom_msgs::srv::I2cService_Request::_read_request_type arg)
  {
    msg_.read_request = std::move(arg);
    return Init_I2cService_Request_read_length(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Request msg_;
};

class Init_I2cService_Request_write_data
{
public:
  explicit Init_I2cService_Request_write_data(::custom_msgs::srv::I2cService_Request & msg)
  : msg_(msg)
  {}
  Init_I2cService_Request_read_request write_data(::custom_msgs::srv::I2cService_Request::_write_data_type arg)
  {
    msg_.write_data = std::move(arg);
    return Init_I2cService_Request_read_request(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Request msg_;
};

class Init_I2cService_Request_device_address
{
public:
  Init_I2cService_Request_device_address()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_I2cService_Request_write_data device_address(::custom_msgs::srv::I2cService_Request::_device_address_type arg)
  {
    msg_.device_address = std::move(arg);
    return Init_I2cService_Request_write_data(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::I2cService_Request>()
{
  return custom_msgs::srv::builder::Init_I2cService_Request_device_address();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_I2cService_Response_message
{
public:
  explicit Init_I2cService_Response_message(::custom_msgs::srv::I2cService_Response & msg)
  : msg_(msg)
  {}
  ::custom_msgs::srv::I2cService_Response message(::custom_msgs::srv::I2cService_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Response msg_;
};

class Init_I2cService_Response_read_data
{
public:
  explicit Init_I2cService_Response_read_data(::custom_msgs::srv::I2cService_Response & msg)
  : msg_(msg)
  {}
  Init_I2cService_Response_message read_data(::custom_msgs::srv::I2cService_Response::_read_data_type arg)
  {
    msg_.read_data = std::move(arg);
    return Init_I2cService_Response_message(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Response msg_;
};

class Init_I2cService_Response_success
{
public:
  Init_I2cService_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_I2cService_Response_read_data success(::custom_msgs::srv::I2cService_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_I2cService_Response_read_data(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::I2cService_Response>()
{
  return custom_msgs::srv::builder::Init_I2cService_Response_success();
}

}  // namespace custom_msgs


namespace custom_msgs
{

namespace srv
{

namespace builder
{

class Init_I2cService_Event_response
{
public:
  explicit Init_I2cService_Event_response(::custom_msgs::srv::I2cService_Event & msg)
  : msg_(msg)
  {}
  ::custom_msgs::srv::I2cService_Event response(::custom_msgs::srv::I2cService_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Event msg_;
};

class Init_I2cService_Event_request
{
public:
  explicit Init_I2cService_Event_request(::custom_msgs::srv::I2cService_Event & msg)
  : msg_(msg)
  {}
  Init_I2cService_Event_response request(::custom_msgs::srv::I2cService_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_I2cService_Event_response(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Event msg_;
};

class Init_I2cService_Event_info
{
public:
  Init_I2cService_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_I2cService_Event_request info(::custom_msgs::srv::I2cService_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_I2cService_Event_request(msg_);
  }

private:
  ::custom_msgs::srv::I2cService_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::srv::I2cService_Event>()
{
  return custom_msgs::srv::builder::Init_I2cService_Event_info();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__BUILDER_HPP_
