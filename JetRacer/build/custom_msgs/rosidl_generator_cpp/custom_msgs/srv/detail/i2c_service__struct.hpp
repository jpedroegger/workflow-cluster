// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:srv/I2cService.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/srv/i2c_service.hpp"


#ifndef CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__STRUCT_HPP_
#define CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__srv__I2cService_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__srv__I2cService_Request __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct I2cService_Request_
{
  using Type = I2cService_Request_<ContainerAllocator>;

  explicit I2cService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_address = 0;
      this->read_request = false;
      this->read_length = 0;
    }
  }

  explicit I2cService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_address = 0;
      this->read_request = false;
      this->read_length = 0;
    }
  }

  // field types and members
  using _device_address_type =
    uint8_t;
  _device_address_type device_address;
  using _write_data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _write_data_type write_data;
  using _read_request_type =
    bool;
  _read_request_type read_request;
  using _read_length_type =
    uint8_t;
  _read_length_type read_length;

  // setters for named parameter idiom
  Type & set__device_address(
    const uint8_t & _arg)
  {
    this->device_address = _arg;
    return *this;
  }
  Type & set__write_data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->write_data = _arg;
    return *this;
  }
  Type & set__read_request(
    const bool & _arg)
  {
    this->read_request = _arg;
    return *this;
  }
  Type & set__read_length(
    const uint8_t & _arg)
  {
    this->read_length = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::srv::I2cService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::srv::I2cService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__srv__I2cService_Request
    std::shared_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__srv__I2cService_Request
    std::shared_ptr<custom_msgs::srv::I2cService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const I2cService_Request_ & other) const
  {
    if (this->device_address != other.device_address) {
      return false;
    }
    if (this->write_data != other.write_data) {
      return false;
    }
    if (this->read_request != other.read_request) {
      return false;
    }
    if (this->read_length != other.read_length) {
      return false;
    }
    return true;
  }
  bool operator!=(const I2cService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct I2cService_Request_

// alias to use template instance with default allocator
using I2cService_Request =
  custom_msgs::srv::I2cService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msgs


#ifndef _WIN32
# define DEPRECATED__custom_msgs__srv__I2cService_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__srv__I2cService_Response __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct I2cService_Response_
{
  using Type = I2cService_Response_<ContainerAllocator>;

  explicit I2cService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit I2cService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _read_data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _read_data_type read_data;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__read_data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->read_data = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::srv::I2cService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::srv::I2cService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__srv__I2cService_Response
    std::shared_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__srv__I2cService_Response
    std::shared_ptr<custom_msgs::srv::I2cService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const I2cService_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->read_data != other.read_data) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const I2cService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct I2cService_Response_

// alias to use template instance with default allocator
using I2cService_Response =
  custom_msgs::srv::I2cService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__srv__I2cService_Event __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__srv__I2cService_Event __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct I2cService_Event_
{
  using Type = I2cService_Event_<ContainerAllocator>;

  explicit I2cService_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit I2cService_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<custom_msgs::srv::I2cService_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::srv::I2cService_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<custom_msgs::srv::I2cService_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::srv::I2cService_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<custom_msgs::srv::I2cService_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::srv::I2cService_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<custom_msgs::srv::I2cService_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::srv::I2cService_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::srv::I2cService_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::srv::I2cService_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::srv::I2cService_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__srv__I2cService_Event
    std::shared_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__srv__I2cService_Event
    std::shared_ptr<custom_msgs::srv::I2cService_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const I2cService_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const I2cService_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct I2cService_Event_

// alias to use template instance with default allocator
using I2cService_Event =
  custom_msgs::srv::I2cService_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msgs

namespace custom_msgs
{

namespace srv
{

struct I2cService
{
  using Request = custom_msgs::srv::I2cService_Request;
  using Response = custom_msgs::srv::I2cService_Response;
  using Event = custom_msgs::srv::I2cService_Event;
};

}  // namespace srv

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__SRV__DETAIL__I2C_SERVICE__STRUCT_HPP_
