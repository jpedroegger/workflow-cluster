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
find_package(geometry_msgs REQUIRED)

link_directories(/home/jetpack/SEAME-Cluster-24-25/JetRacer/install/pca9685_driver/lib)

# Include directories
include_directories(
  include
  ${CMAKE_SOURCE_DIR}/include
  ~/SEAME-Cluster-24-25/JetRacer/install/pca9685_driver/include
  ~/SEAME-Cluster-24-25/JetRacer/install/abstract_driver/include
)

# Add the executable and link necessary libraries
add_executable(${exec_name} ${srcs})

# Link the PCA9685Driver library to the executable
target_link_libraries(${exec_name} PCA9685Driver)  # Link to PCA9685Driver

# Gtest
if(BUILD_TESTING)
  find_package(ament_cmake_gmock REQUIRED)

  # Create test executable
  ament_add_gmock(${PROJECT_NAME}_test 
	  test/src/ServoNodeTest.cpp
	  src/ServoNode.cpp
  )
  
  target_include_directories(${PROJECT_NAME}_test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
	test/include
  )
  
  # Add dependencies to the test target
  ament_target_dependencies(${PROJECT_NAME}_test 
    rclcpp 
    custom_msgs
	geometry_msgs
	pca9685_driver
  )
  target_link_libraries(${PROJECT_NAME}_test PCA9685Driver)
endif()

ament_target_dependencies(${exec_name} rclcpp std_msgs pca9685_driver custom_msgs geometry_msgs)

# Install target
install(TARGETS ${exec_name} DESTINATION lib/${PROJECT_NAME})

ament_package()

