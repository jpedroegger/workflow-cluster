// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/CanFrame.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/can_frame.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__CanFrame __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__CanFrame __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CanFrame_
{
  using Type = CanFrame_<ContainerAllocator>;

  explicit CanFrame_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->data_len = 0ul;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  explicit CanFrame_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->data_len = 0ul;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  // field types and members
  using _id_type =
    uint32_t;
  _id_type id;
  using _data_len_type =
    uint32_t;
  _data_len_type data_len;
  using _data_type =
    std::array<uint8_t, 8>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__data_len(
    const uint32_t & _arg)
  {
    this->data_len = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<uint8_t, 8> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::CanFrame_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::CanFrame_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CanFrame_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CanFrame_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__CanFrame
    std::shared_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__CanFrame
    std::shared_ptr<custom_msgs::msg::CanFrame_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CanFrame_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->data_len != other.data_len) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CanFrame_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CanFrame_

// alias to use template instance with default allocator
using CanFrame =
  custom_msgs::msg::CanFrame_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_HPP_
