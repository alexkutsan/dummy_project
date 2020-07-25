cmake_minimum_required(VERSION 3.5.1)
PROJECT(Proj)

include(ExternalProject)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/)
include(BOOST)
include(Log4CXX)

set(CMAKE_CXX_STANDARD 14)



include_directories(components/include)

add_subdirectory(components/proj)
add_subdirectory(components/utils)
add_subdirectory(components/shared_lib)

add_executable(Proj main.cc)
target_link_libraries(Proj ProjectLib)

configure_file(${CMAKE_SOURCE_DIR}/log4cxx.properties
                ${CMAKE_BINARY_DIR}/log4cxx.properties
                COPYONLY)


enable_testing()
#add_subdirectory(test)
