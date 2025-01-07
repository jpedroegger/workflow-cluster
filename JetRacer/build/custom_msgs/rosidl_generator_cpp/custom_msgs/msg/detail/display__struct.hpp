// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/display.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__Display __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__Display __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Display_
{
  using Type = Display_<ContainerAllocator>;

  explicit Display_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->line1 = "";
      this->line2 = "";
      this->line3 = "";
      this->line4 = "";
    }
  }

  explicit Display_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : line1(_alloc),
    line2(_alloc),
    line3(_alloc),
    line4(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->line1 = "";
      this->line2 = "";
      this->line3 = "";
      this->line4 = "";
    }
  }

  // field types and members
  using _line1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _line1_type line1;
  using _line2_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _line2_type line2;
  using _line3_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _line3_type line3;
  using _line4_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _line4_type line4;

  // setters for named parameter idiom
  Type & set__line1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->line1 = _arg;
    return *this;
  }
  Type & set__line2(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->line2 = _arg;
    return *this;
  }
  Type & set__line3(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->line3 = _arg;
    return *this;
  }
  Type & set__line4(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->line4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::Display_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::Display_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::Display_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::Display_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Display_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Display_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Display_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Display_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::Display_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::Display_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__Display
    std::shared_ptr<custom_msgs::msg::Display_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__Display
    std::shared_ptr<custom_msgs::msg::Display_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Display_ & other) const
  {
    if (this->line1 != other.line1) {
      return false;
    }
    if (this->line2 != other.line2) {
      return false;
    }
    if (this->line3 != other.line3) {
      return false;
    }
    if (this->line4 != other.line4) {
      return false;
    }
    return true;
  }
  bool operator!=(const Display_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Display_

// alias to use template instance with default allocator
using Display =
  custom_msgs::msg::Display_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_HPP_
