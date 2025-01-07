// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:srv/CanService.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/srv/can_service.hpp"


#ifndef CUSTOM_MSGS__SRV__DETAIL__CAN_SERVICE__TRAITS_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__CAN_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/srv/detail/can_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CanService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: can_id
  {
    out << "can_id: ";
    rosidl_generator_traits::value_to_yaml(msg.can_id, out);
    out << ", ";
  }

  // member: write_data
  {
    if (msg.write_data.size() == 0) {
      out << "write_data: []";
    } else {
      out << "write_data: [";
      size_t pending_items = msg.write_data.size();
      for (auto item : msg.write_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: read_request
  {
    out << "read_request: ";
    rosidl_generator_traits::value_to_yaml(msg.read_request, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CanService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: can_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_id: ";
    rosidl_generator_traits::value_to_yaml(msg.can_id, out);
    out << "\n";
  }

  // member: write_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.write_data.size() == 0) {
      out << "write_data: []\n";
    } else {
      out << "write_data:\n";
      for (auto item : msg.write_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: read_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "read_request: ";
    rosidl_generator_traits::value_to_yaml(msg.read_request, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CanService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::srv::CanService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::srv::CanService_Request & msg)
{
  return custom_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::srv::CanService_Request>()
{
  return "custom_msgs::srv::CanService_Request";
}

template<>
inline const char * name<custom_msgs::srv::CanService_Request>()
{
  return "custom_msgs/srv/CanService_Request";
}

template<>
struct has_fixed_size<custom_msgs::srv::CanService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::srv::CanService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::srv::CanService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CanService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: read_data
  {
    if (msg.read_data.size() == 0) {
      out << "read_data: []";
    } else {
      out << "read_data: [";
      size_t pending_items = msg.read_data.size();
      for (auto item : msg.read_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CanService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: read_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.read_data.size() == 0) {
      out << "read_data: []\n";
    } else {
      out << "read_data:\n";
      for (auto item : msg.read_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CanService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::srv::CanService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::srv::CanService_Response & msg)
{
  return custom_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::srv::CanService_Response>()
{
  return "custom_msgs::srv::CanService_Response";
}

template<>
inline const char * name<custom_msgs::srv::CanService_Response>()
{
  return "custom_msgs/srv/CanService_Response";
}

template<>
struct has_fixed_size<custom_msgs::srv::CanService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::srv::CanService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::srv::CanService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace custom_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CanService_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CanService_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CanService_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::srv::CanService_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::srv::CanService_Event & msg)
{
  return custom_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::srv::CanService_Event>()
{
  return "custom_msgs::srv::CanService_Event";
}

template<>
inline const char * name<custom_msgs::srv::CanService_Event>()
{
  return "custom_msgs/srv/CanService_Event";
}

template<>
struct has_fixed_size<custom_msgs::srv::CanService_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::srv::CanService_Event>
  : std::integral_constant<bool, has_bounded_size<custom_msgs::srv::CanService_Request>::value && has_bounded_size<custom_msgs::srv::CanService_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_msgs::srv::CanService_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msgs::srv::CanService>()
{
  return "custom_msgs::srv::CanService";
}

template<>
inline const char * name<custom_msgs::srv::CanService>()
{
  return "custom_msgs/srv/CanService";
}

template<>
struct has_fixed_size<custom_msgs::srv::CanService>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msgs::srv::CanService_Request>::value &&
    has_fixed_size<custom_msgs::srv::CanService_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msgs::srv::CanService>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msgs::srv::CanService_Request>::value &&
    has_bounded_size<custom_msgs::srv::CanService_Response>::value
  >
{
};

template<>
struct is_service<custom_msgs::srv::CanService>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msgs::srv::CanService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msgs::srv::CanService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__SRV__DETAIL__CAN_SERVICE__TRAITS_HPP_
