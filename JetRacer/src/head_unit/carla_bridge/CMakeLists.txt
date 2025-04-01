cmake_minimum_required(VERSION 3.10)
project(carla_bridge)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(carla_msgs REQUIRED)

include_directories(
  include
)

add_executable(carla_bridge_node 
  src/main.cpp
  src/CarlaBridgeNode.cpp
)

ament_target_dependencies(carla_bridge_node
    rclcpp
    geometry_msgs
    carla_msgs
)

install(TARGETS
    carla_bridge_node
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
