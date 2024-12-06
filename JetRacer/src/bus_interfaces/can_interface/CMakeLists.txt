cmake_minimum_required(VERSION 3.8)

project(can_interface)

# Enable compile commands export
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define executable name
set(exec_name ${PROJECT_NAME}_node)

# Add source files
set(srcs
  src/main.cpp
  src/CanInterface.cpp
)

# Include necessary directories
include_directories(
  include
)

# Find dependencies and custom message
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_msgs REQUIRED)

# Fetch external library for CAN driver
include(FetchContent)
FetchContent_Declare(
  sockcanpp
  GIT_REPOSITORY https://github.com/SimonCahill/libsockcanpp.git
  GIT_TAG master
)
FetchContent_MakeAvailable(sockcanpp)

# Add the executable
add_executable(${exec_name} ${srcs})
ament_target_dependencies(${exec_name} rclcpp custom_msgs)

# Link external libraries
target_link_libraries(${exec_name} sockcanpp)

# Install target
install(TARGETS ${exec_name} DESTINATION lib/${PROJECT_NAME})

# Export dependencies
ament_package()

