# CMake generated Testfile for 
# Source directory: /home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/i2c_interface
# Build directory: /home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(i2c_interface_test "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface/test_results/i2c_interface/i2c_interface_test.gtest.xml" "--package-name" "i2c_interface" "--output-file" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface/ament_cmake_gmock/i2c_interface_test.txt" "--command" "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface/i2c_interface_test" "--gtest_output=xml:/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface/test_results/i2c_interface/i2c_interface_test.gtest.xml")
set_tests_properties(i2c_interface_test PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface/i2c_interface_test" TIMEOUT "60" WORKING_DIRECTORY "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/i2c_interface" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock_test.cmake;98;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;90;ament_add_gmock_test;/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/i2c_interface/CMakeLists.txt;40;ament_add_gmock;/home/jetpack/SEAME-Cluster-24-25/JetRacer/src/bus_interfaces/i2c_interface/CMakeLists.txt;0;")
subdirs("gmock")
subdirs("gtest")
