cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#set(BOOST_URL https://dl.bintray.com/boostorg/release/1.73.0/source/boost_1_73_0.tar.bz2)
#SET(Boost_USE_STATIC_LIBS ON)
#add_subdirectory(boost-cmake)

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
