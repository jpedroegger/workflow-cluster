# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-src"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-build"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/tmp"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/src/sockcanpp-populate-stamp"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/src"
  "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/src/sockcanpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/src/sockcanpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/jetpack/SEAME-Cluster-24-25/JetRacer/build/can_interface/_deps/sockcanpp-subbuild/sockcanpp-populate-prefix/src/sockcanpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
