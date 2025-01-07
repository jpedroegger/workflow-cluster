// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/CanFrame.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/can_frame.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CanFrame in the package custom_msgs.
typedef struct custom_msgs__msg__CanFrame
{
  uint32_t id;
  uint32_t data_len;
  uint8_t data[8];
} custom_msgs__msg__CanFrame;

// Struct for a sequence of custom_msgs__msg__CanFrame.
typedef struct custom_msgs__msg__CanFrame__Sequence
{
  custom_msgs__msg__CanFrame * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__CanFrame__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__CAN_FRAME__STRUCT_H_
