cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCES project.cc  Parser.cpp Token.cpp Stack.cpp Calculator.cpp executor.cpp)
add_library(ProjectLib ${SOURCES})

add_executable(project main.cc Parser.cpp Token.cpp Stack.cpp Calculator.cpp executor.cpp)
target_link_libraries(project ProjectLib)

enable_testing()
add_subdirectory(test)
