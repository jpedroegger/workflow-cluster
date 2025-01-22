cmake_minimum_required(VERSION 3.8)

project(battery)

# Export compile commands for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set executable name
set(exec_name ${PROJECT_NAME}_node)

# Add source files
set(srcs
    src/main.cpp
    src/BatteryNode.cpp
)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ina219_driver REQUIRED)
find_package(custom_msgs REQUIRED)
find_package(abstract_driver REQUIRED)

# Include directories
include_directories(
  include
)

# Add the executable and link necessary libraries
add_executable(${exec_name} ${srcs})

# Link the INA219Driver library to the executable
ament_target_dependencies(${exec_name} 
    rclcpp 
    std_msgs 
    ina219_driver 
    custom_msgs 
    abstract_driver
)

# Install the executable
install(TARGETS ${exec_name}
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
