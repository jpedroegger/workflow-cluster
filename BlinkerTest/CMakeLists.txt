cmake_minimum_required(VERSION 3.16)

project(BlinkerTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BlinkerTest
    tst_blinkertest.cpp

    ../cluster_qt/includes/Blinkers.h
    ../cluster_qt/Blinkers.cpp
)
add_test(NAME BlinkerTest COMMAND BlinkerTest)

target_link_libraries(BlinkerTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

