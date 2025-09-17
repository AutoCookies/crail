cmake_minimum_required(VERSION 3.14)
project(crail VERSION 1.0 LANGUAGES CXX)

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
add_library(crail STATIC ${SOURCES})

# Shared library
add_library(crail_shared SHARED ${SOURCES})

# Include headers
target_include_directories(crail PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(crail_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# ============= CÀI ĐẶT =============
include(GNUInstallDirs)

install(TARGETS crail crail_shared
    EXPORT crailTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .a
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}   # .so / .dll
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}   # .exe / .dll
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT crailTargets
    FILE crailConfig.cmake
    NAMESPACE crail::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/crail
)

# ============= EXAMPLES =============
option(CRAIL_BUILD_EXAMPLES "Build examples" ON)

if(CRAIL_BUILD_EXAMPLES)
    add_executable(matrix_demo examples/matrix_demo.cpp)
    target_link_libraries(matrix_demo PRIVATE crail)

    add_executable(calculus_demo examples/calculus_demo.cpp)
    target_link_libraries(calculus_demo PRIVATE crail)
endif()

# ============= TESTS =============
option(CRAIL_BUILD_TESTS "Build tests" ON)

if(CRAIL_BUILD_TESTS)
    enable_testing()
    add_executable(test_linalg tests/test_linalg.cpp)
    target_link_libraries(test_linalg PRIVATE crail)
    add_test(NAME LinalgTests COMMAND test_linalg)

    add_executable(test_calculus tests/test_calculus.cpp)
    target_link_libraries(test_calculus PRIVATE crail)
    add_test(NAME CalculusTests COMMAND test_calculus)
endif()