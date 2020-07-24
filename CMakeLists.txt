cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include_directories(components/include)

add_subdirectory(components/proj)
add_subdirectory(components/utils)

add_executable(Proj main.cc)
target_link_libraries(Proj ProjectLib)
#target_include_directories(Proj PUBLIC
#                                components/proj/include)

enable_testing()
#add_subdirectory(test)
