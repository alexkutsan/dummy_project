include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_executable (FixedQueueTest fixed_size_queue_test.cc)

add_gtest(ProjectTest)
add_gtest(FixedQueueTest)

target_link_libraries(ProjectTest PUBLIC ProjectLib)
