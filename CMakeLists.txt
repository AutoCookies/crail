cmake_minimum_required(VERSION 3.14)
project(mymath VERSION 1.0 LANGUAGES CXX)

# Chuẩn C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============= THƯ VIỆN =============
set(SOURCES
    src/core/linalg.cpp
    src/core/calculus.cpp
    src/objects/matrix.cpp
)

# Static library
add_library(mymath STATIC ${SOURCES})

# Shared library
add_library(mymath_shared SHARED ${SOURCES})

# Include headers
target_include_directories(mymath PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(mymath_shared PUBLIC ${CMAKE_SOURCE_DIR}/include)

# ============= CÀI ĐẶT =============
include(GNUInstallDirs)

install(TARGETS mymath mymath_shared
    EXPORT mymathTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .a
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .so / .dll
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}   # .exe / .dll
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT mymathTargets
    FILE mymathConfig.cmake
    NAMESPACE mymath::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mymath
)

# ============= TESTS =============
option(MYMATH_BUILD_TESTS "Build unit tests" ON)

if(MYMATH_BUILD_TESTS)
    enable_testing()
    add_executable(test_matrix tests/test_matrix.cpp)
    target_link_libraries(test_matrix PRIVATE mymath)
    add_test(NAME MatrixTests COMMAND test_matrix)
endif()

# ============= EXAMPLES =============
option(MYMATH_BUILD_EXAMPLES "Build examples" ON)

if(MYMATH_BUILD_EXAMPLES)
    add_executable(matrix_demo examples/matrix_demo.cpp)
    target_link_libraries(matrix_demo PRIVATE mymath)

    add_executable(calculus_demo examples/calculus_demo.cpp)
    target_link_libraries(calculus_demo PRIVATE mymath)
endif()
