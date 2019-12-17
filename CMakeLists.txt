cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCES calculator.cc utils.h)
add_library(CalcLib ${SOURCES})

add_executable(Calculator main.cc)
target_link_libraries(Calculator CalcLib)

enable_testing()
add_subdirectory(test)
