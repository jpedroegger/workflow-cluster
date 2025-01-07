# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dc_motors_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dc_motors_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dc_motors_FOUND FALSE)
  elseif(NOT dc_motors_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dc_motors_FOUND FALSE)
  endif()
  return()
endif()
set(_dc_motors_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dc_motors_FIND_QUIETLY)
  message(STATUS "Found dc_motors: 0.0.0 (${dc_motors_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dc_motors' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT dc_motors_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dc_motors_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dc_motors_DIR}/${_extra}")
endforeach()
