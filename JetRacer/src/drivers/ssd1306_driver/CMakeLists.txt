cmake_minimum_required(VERSION 3.8)
project(ssd1306_driver)

# Export compile command for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set library name
set(lib_name SSD1306Driver)

# Find dependencies first - moved up
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(abstract_driver REQUIRED)

# Add source files
set(srcs
  src/SSD1306Driver.cpp
)

# Create the shared library
add_library(${lib_name} SHARED ${srcs})

# Set include directories for the library
target_include_directories(${lib_name} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Link against the required dependencies
ament_target_dependencies(${lib_name}
  rclcpp
  std_msgs
  custom_msgs
  abstract_driver
)

# Install
install(
  TARGETS ${lib_name}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  DIRECTORY include/
  DESTINATION include
)

ament_package()
