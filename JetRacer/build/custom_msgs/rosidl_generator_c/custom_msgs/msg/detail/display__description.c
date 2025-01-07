// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/Display.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/display__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__Display__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0xf6, 0x03, 0xb7, 0x79, 0x5c, 0xb5, 0x53,
      0x2a, 0xee, 0xdb, 0x2f, 0x44, 0xdf, 0xcd, 0xeb,
      0xeb, 0xfe, 0xd2, 0x2a, 0xc2, 0x81, 0x56, 0x12,
      0xc8, 0x22, 0x2c, 0x53, 0x65, 0xfa, 0xd8, 0xe9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__Display__TYPE_NAME[] = "custom_msgs/msg/Display";

// Define type names, field names, and default values
static char custom_msgs__msg__Display__FIELD_NAME__line1[] = "line1";
static char custom_msgs__msg__Display__FIELD_NAME__line2[] = "line2";
static char custom_msgs__msg__Display__FIELD_NAME__line3[] = "line3";
static char custom_msgs__msg__Display__FIELD_NAME__line4[] = "line4";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__Display__FIELDS[] = {
  {
    {custom_msgs__msg__Display__FIELD_NAME__line1, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Display__FIELD_NAME__line2, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Display__FIELD_NAME__line3, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Display__FIELD_NAME__line4, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__Display__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__Display__TYPE_NAME, 23, 23},
      {custom_msgs__msg__Display__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string line1\n"
  "string line2\n"
  "string line3\n"
  "string line4";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__Display__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__Display__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__Display__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__Display__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
