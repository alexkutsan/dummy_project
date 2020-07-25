cmake_minimum_required(VERSION 3.5.1)
PROJECT(Proj)
set(CMAKE_CXX_STANDARD 14)


set(LOGGER "log4cxx" CACHE STRING "LOGGER chosen by the user at CMake configure time")
set_property(CACHE LOGGER PROPERTY STRINGS log4cxx boost std none)

include(ExternalProject)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/)


if(LOGGER STREQUAL "log4cxx")
  message(STATUS "Use log4cxx logger")
  include(Log4CXX)
  add_definitions(-DUSE_LOG4CXX_LOGGER)
elseif(LOGGER STREQUAL "boost")
  include(BOOST)
  add_definitions(-DUSE_BOOST_LOGGER)
  message(STATUS "Use boost logger")
elseif(LOGGER STREQUAL "std")
  add_definitions(-DUSE_STD_LOGGER)
  message(STATUS "Use std logger")
elseif(LOGGER STREQUAL "none")
  message(WARNING "Logger turned off")
else()
  message(ERROR "WTF" ${LOGGER})
endif()

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
