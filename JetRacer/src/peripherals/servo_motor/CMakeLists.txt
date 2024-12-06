cmake_minimum_required(VERSION 3.8)

project(servo_motor)

# Export compile command for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set executable name
set(exec_name ${PROJECT_NAME}_node)

# Add source files
set(srcs
    src/main.cpp
    src/ServoNode.cpp
)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(pca9685_driver REQUIRED)
find_package(custom_msgs REQUIRED)

link_directories(/home/jetpack/JetRacer/install/pca9685_driver/lib)

# Include directories
include_directories(
  include
  ${CMAKE_SOURCE_DIR}/include
  ~/JetRacer/install/pca9685_driver/include
)

# Add the executable and link necessary libraries
add_executable(${exec_name} ${srcs})

# Link the PCA9685Driver library to the executable
target_link_libraries(${exec_name} PCA9685Driver)  # Link to PCA9685Driver

ament_target_dependencies(${exec_name} rclcpp std_msgs pca9685_driver custom_msgs)

# Install target
install(TARGETS ${exec_name} DESTINATION lib/${PROJECT_NAME})

ament_package()

