include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_gtest(ProjectTest)
target_link_libraries(ProjectTest PUBLIC ProjectLib)

add_executable (RunTest ${CMAKE_SOURCE_DIR}/run.cc run_tests.cc)
add_gtest(RunTest)

add_executable (CalculatorTest calculator_test.cc
                               ${CMAKE_SOURCE_DIR}/calculator.cc
                               ${CMAKE_SOURCE_DIR}/token.cc
                               ${CMAKE_SOURCE_DIR}/operand.cc
                               ${CMAKE_SOURCE_DIR}/operator.cc)
add_gtest(CalculatorTest)
