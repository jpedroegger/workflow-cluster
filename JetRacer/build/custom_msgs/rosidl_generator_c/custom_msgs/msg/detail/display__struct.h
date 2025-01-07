// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/display.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'line1'
// Member 'line2'
// Member 'line3'
// Member 'line4'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Display in the package custom_msgs.
typedef struct custom_msgs__msg__Display
{
  rosidl_runtime_c__String line1;
  rosidl_runtime_c__String line2;
  rosidl_runtime_c__String line3;
  rosidl_runtime_c__String line4;
} custom_msgs__msg__Display;

// Struct for a sequence of custom_msgs__msg__Display.
typedef struct custom_msgs__msg__Display__Sequence
{
  custom_msgs__msg__Display * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Display__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__DISPLAY__STRUCT_H_
