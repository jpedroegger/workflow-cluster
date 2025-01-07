// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/display__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/display__struct.h"
#include "custom_msgs/msg/detail/display__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // line1, line2, line3, line4
#include "rosidl_runtime_c/string_functions.h"  // line1, line2, line3, line4

// forward declare type support functions


using _Display__ros_msg_type = custom_msgs__msg__Display;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_custom_msgs__msg__Display(
  const custom_msgs__msg__Display * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: line1
  {
    const rosidl_runtime_c__String * str = &ros_message->line1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line2
  {
    const rosidl_runtime_c__String * str = &ros_message->line2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line3
  {
    const rosidl_runtime_c__String * str = &ros_message->line3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line4
  {
    const rosidl_runtime_c__String * str = &ros_message->line4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_deserialize_custom_msgs__msg__Display(
  eprosima::fastcdr::Cdr & cdr,
  custom_msgs__msg__Display * ros_message)
{
  // Field name: line1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->line1.data) {
      rosidl_runtime_c__String__init(&ros_message->line1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->line1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'line1'\n");
      return false;
    }
  }

  // Field name: line2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->line2.data) {
      rosidl_runtime_c__String__init(&ros_message->line2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->line2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'line2'\n");
      return false;
    }
  }

  // Field name: line3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->line3.data) {
      rosidl_runtime_c__String__init(&ros_message->line3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->line3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'line3'\n");
      return false;
    }
  }

  // Field name: line4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->line4.data) {
      rosidl_runtime_c__String__init(&ros_message->line4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->line4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'line4'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__Display(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Display__ros_msg_type * ros_message = static_cast<const _Display__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: line1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line1.size + 1);

  // Field name: line2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line2.size + 1);

  // Field name: line3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line3.size + 1);

  // Field name: line4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line4.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__Display(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: line1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_msgs__msg__Display;
    is_plain =
      (
      offsetof(DataType, line4) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
bool cdr_serialize_key_custom_msgs__msg__Display(
  const custom_msgs__msg__Display * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: line1
  {
    const rosidl_runtime_c__String * str = &ros_message->line1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line2
  {
    const rosidl_runtime_c__String * str = &ros_message->line2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line3
  {
    const rosidl_runtime_c__String * str = &ros_message->line3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: line4
  {
    const rosidl_runtime_c__String * str = &ros_message->line4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_key_custom_msgs__msg__Display(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Display__ros_msg_type * ros_message = static_cast<const _Display__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: line1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line1.size + 1);

  // Field name: line2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line2.size + 1);

  // Field name: line3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line3.size + 1);

  // Field name: line4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->line4.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_key_custom_msgs__msg__Display(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: line1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: line4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_msgs__msg__Display;
    is_plain =
      (
      offsetof(DataType, line4) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Display__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_msgs__msg__Display * ros_message = static_cast<const custom_msgs__msg__Display *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_msgs__msg__Display(ros_message, cdr);
}

static bool _Display__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_msgs__msg__Display * ros_message = static_cast<custom_msgs__msg__Display *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_msgs__msg__Display(cdr, ros_message);
}

static uint32_t _Display__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__Display(
      untyped_ros_message, 0));
}

static size_t _Display__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_msgs__msg__Display(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Display = {
  "custom_msgs::msg",
  "Display",
  _Display__cdr_serialize,
  _Display__cdr_deserialize,
  _Display__get_serialized_size,
  _Display__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Display__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Display,
  get_message_typesupport_handle_function,
  &custom_msgs__msg__Display__get_type_hash,
  &custom_msgs__msg__Display__get_type_description,
  &custom_msgs__msg__Display__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, Display)() {
  return &_Display__type_support;
}

#if defined(__cplusplus)
}
#endif
