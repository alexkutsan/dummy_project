cmake_minimum_required(VERSION 3.7)
project(commandline_videostore_cpp)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
enable_testing()



set(SOURCES run.h run.cc movie.cc rental.cc customer.cc)
add_library(StoreLib ${SOURCES})

add_executable(commandline_videostore_cpp main.cc)
target_link_libraries(commandline_videostore_cpp StoreLib)

add_subdirectory(test)
