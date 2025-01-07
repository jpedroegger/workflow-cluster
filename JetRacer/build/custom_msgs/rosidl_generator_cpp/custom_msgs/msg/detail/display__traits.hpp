// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/display.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DISPLAY__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DISPLAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/display__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Display & msg,
  std::ostream & out)
{
  out << "{";
  // member: line1
  {
    out << "line1: ";
    rosidl_generator_traits::value_to_yaml(msg.line1, out);
    out << ", ";
  }

  // member: line2
  {
    out << "line2: ";
    rosidl_generator_traits::value_to_yaml(msg.line2, out);
    out << ", ";
  }

  // member: line3
  {
    out << "line3: ";
    rosidl_generator_traits::value_to_yaml(msg.line3, out);
    out << ", ";
  }

  // member: line4
  {
    out << "line4: ";
    rosidl_generator_traits::value_to_yaml(msg.line4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Display & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: line1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line1: ";
    rosidl_generator_traits::value_to_yaml(msg.line1, out);
    out << "\n";
  }

  // member: line2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line2: ";
    rosidl_generator_traits::value_to_yaml(msg.line2, out);
    out << "\n";
  }

  // member: line3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line3: ";
    rosidl_generator_traits::value_to_yaml(msg.line3, out);
    out << "\n";
  }

  // member: line4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line4: ";
    rosidl_generator_traits::value_to_yaml(msg.line4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Display & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::Display & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::Display & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::Display>()
{
  return "custom_msgs::msg::Display";
}

template<>
inline const char * name<custom_msgs::msg::Display>()
{
  return "custom_msgs/msg/Display";
}

template<>
struct has_fixed_size<custom_msgs::msg::Display>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::Display>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::Display>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__DISPLAY__TRAITS_HPP_
