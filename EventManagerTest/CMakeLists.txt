cmake_minimum_required(VERSION 3.16)

project(EventManagerTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(EventManagerTest
#     tst_eventmanagertest.cpp
#     tst_processkeystates.cpp
# )

set(SHARED_SOURCES
    ../cluster_qt/includes/ArrowSymbolWidget.h
    ../cluster_qt/includes/SpeedometerWidget.h
    ../cluster_qt/includes/Blinkers.h
    ../cluster_qt/includes/EventManager.h
    ../cluster_qt/ArrowSymbolWidget.cpp
    ../cluster_qt/SpeedometerWidget.cpp
    ../cluster_qt/Blinkers.cpp
    ../cluster_qt/EventManager.cpp
)

macro(add_event_manager_test TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME}_test ${TEST_FILE} ${SHARED_SOURCES})
    target_link_libraries(${TEST_NAME}_test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME}_test)
endmacro()


# add_test(NAME EventManagerTest COMMAND EventManagerTest)

add_event_manager_test(EventManagerTest tst_eventmanagertest.cpp)
add_event_manager_test(EventManagerTestProcessKeys tst_processkeystates.cpp)

# target_link_libraries(EventManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

# target_sources(EventManagerTest PRIVATE
#     ../cluster_qt/includes/ArrowSymbolWidget.h
#     ../cluster_qt/includes/SpeedometerWidget.h
#     ../cluster_qt/includes/Blinkers.h
#     ../cluster_qt/includes/EventManager.h
#     ../cluster_qt/ArrowSymbolWidget.cpp
#     ../cluster_qt/SpeedometerWidget.cpp
#     ../cluster_qt/Blinkers.cpp
#     ../cluster_qt/EventManager.cpp
# )
