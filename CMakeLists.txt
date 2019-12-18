cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCES
    project.cc
    polishcalc.cc
    polishcalclogic.cc
    polishcalcutils.cc
)
add_library(ProjectLib ${SOURCES})

add_executable(project main.cc)
target_link_libraries(project ProjectLib)

enable_testing()
add_subdirectory(test)
