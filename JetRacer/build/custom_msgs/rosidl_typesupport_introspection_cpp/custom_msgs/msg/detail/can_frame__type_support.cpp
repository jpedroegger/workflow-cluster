// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_msgs:msg/CanFrame.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msgs/msg/detail/can_frame__functions.h"
#include "custom_msgs/msg/detail/can_frame__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CanFrame_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msgs::msg::CanFrame(_init);
}

void CanFrame_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msgs::msg::CanFrame *>(message_memory);
  typed_message->~CanFrame();
}

size_t size_function__CanFrame__data(const void * untyped_member)
{
  (void)untyped_member;
  return 8;
}

const void * get_const_function__CanFrame__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 8> *>(untyped_member);
  return &member[index];
}

void * get_function__CanFrame__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 8> *>(untyped_member);
  return &member[index];
}

void fetch_function__CanFrame__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__CanFrame__data(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__CanFrame__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__CanFrame__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CanFrame_message_member_array[3] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::CanFrame, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data_len",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::CanFrame, data_len),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    8,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::CanFrame, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__CanFrame__data,  // size() function pointer
    get_const_function__CanFrame__data,  // get_const(index) function pointer
    get_function__CanFrame__data,  // get(index) function pointer
    fetch_function__CanFrame__data,  // fetch(index, &value) function pointer
    assign_function__CanFrame__data,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CanFrame_message_members = {
  "custom_msgs::msg",  // message namespace
  "CanFrame",  // message name
  3,  // number of fields
  sizeof(custom_msgs::msg::CanFrame),
  false,  // has_any_key_member_
  CanFrame_message_member_array,  // message members
  CanFrame_init_function,  // function to initialize message memory (memory has to be allocated)
  CanFrame_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CanFrame_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CanFrame_message_members,
  get_message_typesupport_handle_function,
  &custom_msgs__msg__CanFrame__get_type_hash,
  &custom_msgs__msg__CanFrame__get_type_description,
  &custom_msgs__msg__CanFrame__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msgs::msg::CanFrame>()
{
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::CanFrame_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msgs, msg, CanFrame)() {
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::CanFrame_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
