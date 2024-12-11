// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:srv/I2cService.idl
// generated code does not contain a copyright notice

#include "custom_msgs/srv/detail/i2c_service__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__srv__I2cService__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x83, 0xc4, 0xa9, 0x3d, 0x3c, 0x04, 0xb4, 0x53,
      0x71, 0x9f, 0x59, 0x6c, 0x24, 0xc4, 0x9a, 0x87,
      0x27, 0xb6, 0x0a, 0x68, 0x6d, 0x1c, 0x28, 0xca,
      0xee, 0xaf, 0x62, 0xd4, 0xf0, 0xa7, 0x9c, 0x7c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__srv__I2cService_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9b, 0xbd, 0xef, 0xc7, 0x8b, 0x74, 0x9d, 0x0a,
      0x45, 0x12, 0x25, 0x2e, 0x51, 0x35, 0xde, 0x2a,
      0x8e, 0xb9, 0x64, 0x3e, 0x87, 0x54, 0x0d, 0x87,
      0xf6, 0x11, 0x11, 0xac, 0xa1, 0xcc, 0x08, 0x66,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__srv__I2cService_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfd, 0x86, 0x24, 0xff, 0xd0, 0xe0, 0xf8, 0xe9,
      0x01, 0x66, 0x45, 0xba, 0xdb, 0xbd, 0xe1, 0xb0,
      0xfe, 0x4a, 0x65, 0x00, 0x97, 0x1b, 0xa5, 0x91,
      0x8a, 0xf5, 0xa8, 0xff, 0x85, 0x71, 0x90, 0x94,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__srv__I2cService_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa1, 0x28, 0x94, 0xc0, 0xc9, 0xba, 0xc6, 0x92,
      0x39, 0x75, 0x7a, 0xb1, 0xee, 0x6c, 0x4a, 0xde,
      0xaf, 0xa3, 0xae, 0x40, 0x3c, 0x26, 0xb9, 0xbb,
      0xc9, 0xc1, 0x69, 0x73, 0x3a, 0xfb, 0x7e, 0x46,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char custom_msgs__srv__I2cService__TYPE_NAME[] = "custom_msgs/srv/I2cService";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char custom_msgs__srv__I2cService_Event__TYPE_NAME[] = "custom_msgs/srv/I2cService_Event";
static char custom_msgs__srv__I2cService_Request__TYPE_NAME[] = "custom_msgs/srv/I2cService_Request";
static char custom_msgs__srv__I2cService_Response__TYPE_NAME[] = "custom_msgs/srv/I2cService_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char custom_msgs__srv__I2cService__FIELD_NAME__request_message[] = "request_message";
static char custom_msgs__srv__I2cService__FIELD_NAME__response_message[] = "response_message";
static char custom_msgs__srv__I2cService__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field custom_msgs__srv__I2cService__FIELDS[] = {
  {
    {custom_msgs__srv__I2cService__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_msgs__srv__I2cService_Event__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__srv__I2cService__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Event__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__srv__I2cService__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__srv__I2cService__TYPE_NAME, 26, 26},
      {custom_msgs__srv__I2cService__FIELDS, 3, 3},
    },
    {custom_msgs__srv__I2cService__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = custom_msgs__srv__I2cService_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_msgs__srv__I2cService_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = custom_msgs__srv__I2cService_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_msgs__srv__I2cService_Request__FIELD_NAME__device_address[] = "device_address";
static char custom_msgs__srv__I2cService_Request__FIELD_NAME__write_data[] = "write_data";
static char custom_msgs__srv__I2cService_Request__FIELD_NAME__read_request[] = "read_request";
static char custom_msgs__srv__I2cService_Request__FIELD_NAME__read_length[] = "read_length";

static rosidl_runtime_c__type_description__Field custom_msgs__srv__I2cService_Request__FIELDS[] = {
  {
    {custom_msgs__srv__I2cService_Request__FIELD_NAME__device_address, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Request__FIELD_NAME__write_data, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Request__FIELD_NAME__read_request, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Request__FIELD_NAME__read_length, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__srv__I2cService_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
      {custom_msgs__srv__I2cService_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_msgs__srv__I2cService_Response__FIELD_NAME__success[] = "success";
static char custom_msgs__srv__I2cService_Response__FIELD_NAME__read_data[] = "read_data";
static char custom_msgs__srv__I2cService_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field custom_msgs__srv__I2cService_Response__FIELDS[] = {
  {
    {custom_msgs__srv__I2cService_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Response__FIELD_NAME__read_data, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Response__FIELD_NAME__message, 7, 7},
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
custom_msgs__srv__I2cService_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
      {custom_msgs__srv__I2cService_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_msgs__srv__I2cService_Event__FIELD_NAME__info[] = "info";
static char custom_msgs__srv__I2cService_Event__FIELD_NAME__request[] = "request";
static char custom_msgs__srv__I2cService_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field custom_msgs__srv__I2cService_Event__FIELDS[] = {
  {
    {custom_msgs__srv__I2cService_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__srv__I2cService_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__srv__I2cService_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__srv__I2cService_Event__TYPE_NAME, 32, 32},
      {custom_msgs__srv__I2cService_Event__FIELDS, 3, 3},
    },
    {custom_msgs__srv__I2cService_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = custom_msgs__srv__I2cService_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_msgs__srv__I2cService_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "uint8 device_address  # Address of the I2C device\n"
  "uint8[] write_data    # Data to write to the device\n"
  "bool read_request     # Whether a read operation is requested\n"
  "uint8 read_length     # Number of bytes to read if read_request is true\n"
  "---\n"
  "# Response\n"
  "bool success          # True if the operation was successful\n"
  "uint8[] read_data     # Data read from the device (if read_request is true)\n"
  "string message        # For error messages or success confirmation";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__srv__I2cService__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__srv__I2cService__TYPE_NAME, 26, 26},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 465, 465},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__srv__I2cService_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__srv__I2cService_Request__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__srv__I2cService_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__srv__I2cService_Response__TYPE_NAME, 35, 35},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__srv__I2cService_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__srv__I2cService_Event__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__srv__I2cService__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__srv__I2cService__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_msgs__srv__I2cService_Event__get_individual_type_description_source(NULL);
    sources[3] = *custom_msgs__srv__I2cService_Request__get_individual_type_description_source(NULL);
    sources[4] = *custom_msgs__srv__I2cService_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__srv__I2cService_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__srv__I2cService_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__srv__I2cService_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__srv__I2cService_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__srv__I2cService_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__srv__I2cService_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_msgs__srv__I2cService_Request__get_individual_type_description_source(NULL);
    sources[3] = *custom_msgs__srv__I2cService_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
