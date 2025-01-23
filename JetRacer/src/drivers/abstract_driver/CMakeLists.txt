cmake_minimum_required(VERSION 3.8)

project(abstract_driver)

# Export compile command for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set library name
set(lib_name AbstractDriver)

include_directories(
  include
)

# Add source files
set(srcs
	src/ADriver.cpp
	include/DriverException.hpp
)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_msgs REQUIRED)
find_package(fmt REQUIRED)

# Create the shared library
add_library(${lib_name} SHARED ${srcs})

target_include_directories(AbstractDriver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(
  TARGETS AbstractDriver
  EXPORT abstract_driver_targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Link against the required dependencies
ament_target_dependencies(${lib_name} rclcpp custom_msgs fmt)

# Export the libraries
install(TARGETS ${lib_name} DESTINATION lib)
install(
  DIRECTORY include/
  DESTINATION include
)

ament_export_targets(abstract_driver_targets HAS_LIBRARY_TARGET)
ament_export_dependencies(${dependencies})
ament_package()
