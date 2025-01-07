// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/display.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DISPLAY__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DISPLAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/display__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Display_line4
{
public:
  explicit Init_Display_line4(::custom_msgs::msg::Display & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Display line4(::custom_msgs::msg::Display::_line4_type arg)
  {
    msg_.line4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Display msg_;
};

class Init_Display_line3
{
public:
  explicit Init_Display_line3(::custom_msgs::msg::Display & msg)
  : msg_(msg)
  {}
  Init_Display_line4 line3(::custom_msgs::msg::Display::_line3_type arg)
  {
    msg_.line3 = std::move(arg);
    return Init_Display_line4(msg_);
  }

private:
  ::custom_msgs::msg::Display msg_;
};

class Init_Display_line2
{
public:
  explicit Init_Display_line2(::custom_msgs::msg::Display & msg)
  : msg_(msg)
  {}
  Init_Display_line3 line2(::custom_msgs::msg::Display::_line2_type arg)
  {
    msg_.line2 = std::move(arg);
    return Init_Display_line3(msg_);
  }

private:
  ::custom_msgs::msg::Display msg_;
};

class Init_Display_line1
{
public:
  Init_Display_line1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Display_line2 line1(::custom_msgs::msg::Display::_line1_type arg)
  {
    msg_.line1 = std::move(arg);
    return Init_Display_line2(msg_);
  }

private:
  ::custom_msgs::msg::Display msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Display>()
{
  return custom_msgs::msg::builder::Init_Display_line1();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DISPLAY__BUILDER_HPP_
