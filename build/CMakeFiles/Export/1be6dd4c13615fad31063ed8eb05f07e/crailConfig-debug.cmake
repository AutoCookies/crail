#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "crail::crail" for configuration "Debug"
set_property(TARGET crail::crail APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(crail::crail PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcrail.a"
  )

list(APPEND _cmake_import_check_targets crail::crail )
list(APPEND _cmake_import_check_files_for_crail::crail "${_IMPORT_PREFIX}/lib/libcrail.a" )

# Import target "crail::crail_shared" for configuration "Debug"
set_property(TARGET crail::crail_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(crail::crail_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libcrail_shared.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libcrail_shared.dll"
  )

list(APPEND _cmake_import_check_targets crail::crail_shared )
list(APPEND _cmake_import_check_files_for_crail::crail_shared "${_IMPORT_PREFIX}/lib/libcrail_shared.dll.a" "${_IMPORT_PREFIX}/bin/libcrail_shared.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
