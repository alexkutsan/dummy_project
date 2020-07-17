include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_gtest(ProjectTest)
target_link_libraries(ProjectTest PUBLIC ProjectLib)

add_executable (RunTest ${CMAKE_SOURCE_DIR}/run.cc run_tests.cc)
add_gtest(RunTest)

add_executable (CalculatorTest ${CMAKE_SOURCE_DIR}/calculator.cc calculator_test.cc)
add_gtest(CalculatorTest)
