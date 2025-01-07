# CMake generated Testfile for 
# Source directory: /home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/can_interface
# Build directory: /home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(can_interface_test "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/test_results/can_interface/can_interface_test.gtest.xml" "--package-name" "can_interface" "--output-file" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/ament_cmake_gmock/can_interface_test.txt" "--command" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/can_interface_test" "--gtest_output=xml:/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/test_results/can_interface/can_interface_test.gtest.xml")
set_tests_properties(can_interface_test PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/can_interface_test" TIMEOUT "60" WORKING_DIRECTORY "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock_test.cmake;98;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;90;ament_add_gmock_test;/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/can_interface/CMakeLists.txt;51;ament_add_gmock;/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/can_interface/CMakeLists.txt;0;")
subdirs("_deps/sockcanpp-build")
subdirs("gmock")
subdirs("gtest")
