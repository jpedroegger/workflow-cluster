ION_MAJOR}::Widgets
                Qt${QT_VERSION_MAJOR}::Test
                rclcpp::rclcpp
                std_msgs::std_msgs
                custom_msgs::custom_msgs
            )
        endforeach()
    endforeach()
endfunction()cmake_minimum_required(VERSION 3.16)

project(cluster_tests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(custom_msgs REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
    ${rclcpp_INCLUDE_DIRS}
    ${std_msgs_INCLUDE_DIRS}
    ${custom_msgs_INCLUDE_DIRS}
)


add_library(ClusterShared
    ../includes/ArrowSymbolWidget.h
    ../includes/SpeedometerWidget.h
    ../includes/Blinkers.h
    ../includes/EventManager.h
    ../includes/TopBar.h

    ../includes/RosNode.hpp


    ../sources/ArrowSymbolWidget.cpp
    ../sources/SpeedometerWidget.cpp
    ../sources/Blinkers.cpp
    ../sources/EventManager.cpp
    ../sources/TopBar.cpp

    ../sources/RosNode.cpp

)

# target_link_libraries(ClusterShared PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ClusterShared PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    rclcpp::rclcpp
    std_msgs::std_msgs
    custom_msgs::custom_msgs
)

function(SETUP_TESTS)
    foreach(test_folder ${ARGN})
        file(GLOB test_files "${test_folder}/*.cpp") # Store the .cpp files into test_files.
        foreach(test_file ${test_files})
            get_filename_component(_testname ${test_file} NAME_WE) # Get the filename without the extension (WE).
            add_executable(${_testname} ${test_file})
            add_test(NAME ${_testname} COMMAND ${_testname})
            target_link_libraries(${_testname} PRIVATE 
                ClusterShared
                Qt${QT_VERSION_MAJOR}::Widgets
                Qt${QT_VERSION_MAJOR}::Test
                rclcpp::rclcpp
                std_msgs::std_msgs
                custom_msgs::custom_msgs
            )
        endforeach()
    endforeach()
endfunction()

SETUP_TESTS(
    EventManagerTest
    BlinkerTest
    TopBarTest
    SpeedometerTest
)

ament_package() 
