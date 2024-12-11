// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CanFrame.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/can_frame.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/can_frame__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CanFrame_data
{
public:
  explicit Init_CanFrame_data(::custom_msgs::msg::CanFrame & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CanFrame data(::custom_msgs::msg::CanFrame::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CanFrame msg_;
};

class Init_CanFrame_data_len
{
public:
  explicit Init_CanFrame_data_len(::custom_msgs::msg::CanFrame & msg)
  : msg_(msg)
  {}
  Init_CanFrame_data data_len(::custom_msgs::msg::CanFrame::_data_len_type arg)
  {
    msg_.data_len = std::move(arg);
    return Init_CanFrame_data(msg_);
  }

private:
  ::custom_msgs::msg::CanFrame msg_;
};

class Init_CanFrame_id
{
public:
  Init_CanFrame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CanFrame_data_len id(::custom_msgs::msg::CanFrame::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_CanFrame_data_len(msg_);
  }

private:
  ::custom_msgs::msg::CanFrame msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CanFrame>()
{
  return custom_msgs::msg::builder::Init_CanFrame_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__BUILDER_HPP_
