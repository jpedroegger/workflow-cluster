// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/CanFrame.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/can_frame__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__CanFrame__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0x2e, 0xc9, 0x1d, 0x4a, 0x6a, 0xbc, 0x4f,
      0x5a, 0x7c, 0x64, 0xdb, 0x70, 0x4f, 0x8d, 0xc4,
      0xea, 0x0e, 0xe6, 0x22, 0x57, 0xb3, 0x9d, 0x95,
      0xf2, 0x72, 0x4a, 0xf2, 0xf7, 0xcf, 0xf6, 0x36,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__CanFrame__TYPE_NAME[] = "custom_msgs/msg/CanFrame";

// Define type names, field names, and default values
static char custom_msgs__msg__CanFrame__FIELD_NAME__id[] = "id";
static char custom_msgs__msg__CanFrame__FIELD_NAME__data_len[] = "data_len";
static char custom_msgs__msg__CanFrame__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__CanFrame__FIELDS[] = {
  {
    {custom_msgs__msg__CanFrame__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__CanFrame__FIELD_NAME__data_len, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__CanFrame__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_ARRAY,
      8,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__CanFrame__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__CanFrame__TYPE_NAME, 24, 24},
      {custom_msgs__msg__CanFrame__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint32 id\n"
  "uint32 data_len\n"
  "uint8[8] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__CanFrame__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__CanFrame__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 40, 40},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__CanFrame__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__CanFrame__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
