// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from custom_msgs:srv/CanService.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_msgs/srv/detail/can_service__struct.h"
#include "custom_msgs/srv/detail/can_service__type_support.h"
#include "custom_msgs/srv/detail/can_service__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CanService_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CanService_Request_type_support_ids_t;

static const _CanService_Request_type_support_ids_t _CanService_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CanService_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CanService_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CanService_Request_type_support_symbol_names_t _CanService_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, srv, CanService_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, srv, CanService_Request)),
  }
};

typedef struct _CanService_Request_type_support_data_t
{
  void * data[2];
} _CanService_Request_type_support_data_t;

static _CanService_Request_type_support_data_t _CanService_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CanService_Request_message_typesupport_map = {
  2,
  "custom_msgs",
  &_CanService_Request_message_typesupport_ids.typesupport_identifier[0],
  &_CanService_Request_message_typesupport_symbol_names.symbol_name[0],
  &_CanService_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CanService_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CanService_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_msgs__srv__CanService_Request__get_type_hash,
  &custom_msgs__srv__CanService_Request__get_type_description,
  &custom_msgs__srv__CanService_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_msgs, srv, CanService_Request)() {
  return &::custom_msgs::srv::rosidl_typesupport_c::CanService_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__struct.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__type_support.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CanService_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CanService_Response_type_support_ids_t;

static const _CanService_Response_type_support_ids_t _CanService_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CanService_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CanService_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CanService_Response_type_support_symbol_names_t _CanService_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, srv, CanService_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, srv, CanService_Response)),
  }
};

typedef struct _CanService_Response_type_support_data_t
{
  void * data[2];
} _CanService_Response_type_support_data_t;

static _CanService_Response_type_support_data_t _CanService_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CanService_Response_message_typesupport_map = {
  2,
  "custom_msgs",
  &_CanService_Response_message_typesupport_ids.typesupport_identifier[0],
  &_CanService_Response_message_typesupport_symbol_names.symbol_name[0],
  &_CanService_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CanService_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CanService_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_msgs__srv__CanService_Response__get_type_hash,
  &custom_msgs__srv__CanService_Response__get_type_description,
  &custom_msgs__srv__CanService_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_msgs, srv, CanService_Response)() {
  return &::custom_msgs::srv::rosidl_typesupport_c::CanService_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__struct.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__type_support.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _CanService_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CanService_Event_type_support_ids_t;

static const _CanService_Event_type_support_ids_t _CanService_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CanService_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CanService_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CanService_Event_type_support_symbol_names_t _CanService_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, srv, CanService_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, srv, CanService_Event)),
  }
};

typedef struct _CanService_Event_type_support_data_t
{
  void * data[2];
} _CanService_Event_type_support_data_t;

static _CanService_Event_type_support_data_t _CanService_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CanService_Event_message_typesupport_map = {
  2,
  "custom_msgs",
  &_CanService_Event_message_typesupport_ids.typesupport_identifier[0],
  &_CanService_Event_message_typesupport_symbol_names.symbol_name[0],
  &_CanService_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CanService_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CanService_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &custom_msgs__srv__CanService_Event__get_type_hash,
  &custom_msgs__srv__CanService_Event__get_type_description,
  &custom_msgs__srv__CanService_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_msgs, srv, CanService_Event)() {
  return &::custom_msgs::srv::rosidl_typesupport_c::CanService_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_msgs/srv/detail/can_service__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace custom_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _CanService_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CanService_type_support_ids_t;

static const _CanService_type_support_ids_t _CanService_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CanService_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CanService_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CanService_type_support_symbol_names_t _CanService_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, srv, CanService)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, srv, CanService)),
  }
};

typedef struct _CanService_type_support_data_t
{
  void * data[2];
} _CanService_type_support_data_t;

static _CanService_type_support_data_t _CanService_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CanService_service_typesupport_map = {
  2,
  "custom_msgs",
  &_CanService_service_typesupport_ids.typesupport_identifier[0],
  &_CanService_service_typesupport_symbol_names.symbol_name[0],
  &_CanService_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t CanService_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CanService_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &CanService_Request_message_type_support_handle,
  &CanService_Response_message_type_support_handle,
  &CanService_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msgs,
    srv,
    CanService
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    custom_msgs,
    srv,
    CanService
  ),
  &custom_msgs__srv__CanService__get_type_hash,
  &custom_msgs__srv__CanService__get_type_description,
  &custom_msgs__srv__CanService__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, custom_msgs, srv, CanService)() {
  return &::custom_msgs::srv::rosidl_typesupport_c::CanService_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
