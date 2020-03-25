cmake_minimum_required(VERSION 3.14)

project(bench LANGUAGES CXX)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(
    STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
 REQUIRES
 benchmark/1.5.0
 BASIC_SETUP CMAKE_TARGETS
 BUILD missing
 )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONAN_SYSTEM_INCLUDES "On")

add_executable(bench bench.cpp)
target_link_libraries(bench PRIVATE CONAN_PKG::benchmark)

add_executable(bench_frame bench.cpp)
target_compile_options(bench_frame PRIVATE -fno-omit-frame-pointer)
target_link_libraries(bench_frame PRIVATE CONAN_PKG::benchmark)

add_custom_command(TARGET bench
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)

