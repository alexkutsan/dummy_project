include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (CalculatorTest calculator_test.cc utils_test.cc)
add_gtest(CalculatorTest)
target_link_libraries(CalculatorTest PUBLIC CalcLib)
