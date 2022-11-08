cmake_minimum_required (VERSION 3.10)

# Setup GoogleTest
configure_file(CMakeLists.txt.ini googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
 RESULT_VARIABLE result
 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
 message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
 RESULT_VARIABLE result
 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
 message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#  include_directories("${gtest_SOURCE_DIR}/include")
#endif()

project (Factorial_test)

set(SOURCES test.cpp ../src/Factorial.cpp)

set(HEADERS ../src/Factorial.h)

add_executable(Factorial_test ${SOURCES} ${HEADERS})
set_property(TARGET Factorial_test PROPERTY CXX_STANDARD 17)
set_property(TARGET Factorial_test PROPERTY CXX_STANDARD_REQUIRED ON)
include_directories(../src)
target_link_libraries(Factorial_test gtest_main)
enable_testing()
add_test(NAME Factorial_test COMMAND Factorial_test)
