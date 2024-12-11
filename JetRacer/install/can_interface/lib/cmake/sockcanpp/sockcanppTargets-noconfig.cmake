#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sockcanpp::sockcanpp" for configuration ""
set_property(TARGET sockcanpp::sockcanpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sockcanpp::sockcanpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/sockcanpp.so.1.1.0"
  IMPORTED_SONAME_NOCONFIG "sockcanpp.so.1.1.0"
  )

list(APPEND _cmake_import_check_targets sockcanpp::sockcanpp )
list(APPEND _cmake_import_check_files_for_sockcanpp::sockcanpp "${_IMPORT_PREFIX}/lib/sockcanpp.so.1.1.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
