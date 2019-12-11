cmake_minimum_required(VERSION 3.5)
include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_gtest(ProjectTest)
target_link_libraries(ProjectTest PUBLIC ProjectLib)
