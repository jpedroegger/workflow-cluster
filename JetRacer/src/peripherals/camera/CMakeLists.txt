cmake_minimum_required(VERSION 3.8)

# Project name
project(camera)

# Export compile commands for tools like LSP (Language Server Protocol)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the executable name
set(exec_name ${PROJECT_NAME}_node)

# Add source files
set(srcs
    src/main.cpp
    src/CameraNode.cpp
)

# Find ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(image_transport REQUIRED)

# Find OpenCV (native CMake support)
find_package(OpenCV REQUIRED)

# Add libcamera (using PkgConfig)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCAMERA REQUIRED libcamera)

# Include directories (header files)
include_directories(
  include                      # Your project's include directory
  ${CMAKE_SOURCE_DIR}/include  # Explicitly adding the source include
  ${OpenCV_INCLUDE_DIRS}       # OpenCV headers
  ${LIBCAMERA_INCLUDE_DIRS}    # libcamera headers (from pkg-config)
)

# Add the executable
add_executable(${exec_name} ${srcs})

# Link libraries
target_link_libraries(${exec_name}
  ${OpenCV_LIBS}             # Link OpenCV libraries
  ${LIBCAMERA_LIBRARIES}     # Link libcamera libraries (from pkg-config)
)

# Add ROS 2 dependencies
ament_target_dependencies(${exec_name}
  rclcpp
  sensor_msgs
  image_transport
)

# Install the executable
install(TARGETS ${exec_name} DESTINATION lib/${PROJECT_NAME})

# Mark as an ament package
ament_package()

