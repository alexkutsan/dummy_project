include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_gtest(ProjectTest)
target_link_libraries(ProjectTest PUBLIC ProjectLib)

add_executable (RunTest ${CMAKE_SOURCE_DIR}/run.cc run_tests.cc)
add_gtest(RunTest)

add_executable(CalculatorTest
    ${CMAKE_CURRENT_SOURCE_DIR}/calculator_test.cpp
    ${CMAKE_SOURCE_DIR}/src/Calculator/calculator.cpp)
add_gtest(CalculatorTest)
