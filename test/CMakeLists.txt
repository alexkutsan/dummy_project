include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (RPNCalculatorTest rpncalculator_test.cpp)
add_gtest(RPNCalculatorTest)
target_link_libraries(RPNCalculatorTest PUBLIC ProjectLib)

add_executable (RunTest ${CMAKE_SOURCE_DIR}/run.cpp run_tests.cpp)
add_gtest(RunTest)
