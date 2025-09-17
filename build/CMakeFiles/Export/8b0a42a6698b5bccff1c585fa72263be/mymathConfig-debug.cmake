#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mymath::mymath" for configuration "Debug"
set_property(TARGET mymath::mymath APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(mymath::mymath PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libmymath.a"
  )

list(APPEND _cmake_import_check_targets mymath::mymath )
list(APPEND _cmake_import_check_files_for_mymath::mymath "${_IMPORT_PREFIX}/lib/libmymath.a" )

# Import target "mymath::mymath_shared" for configuration "Debug"
set_property(TARGET mymath::mymath_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(mymath::mymath_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libmymath_shared.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libmymath_shared.dll"
  )

list(APPEND _cmake_import_check_targets mymath::mymath_shared )
list(APPEND _cmake_import_check_files_for_mymath::mymath_shared "${_IMPORT_PREFIX}/lib/libmymath_shared.dll.a" "${_IMPORT_PREFIX}/bin/libmymath_shared.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
