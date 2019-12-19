include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (ProjectTest project_test.cc)
add_executable (CalculatorTest calculator_test.cc)
add_executable (ParserTest parser_test.cc)
add_gtest(ProjectTest)
add_gtest(CalculatorTest)
add_gtest(ParserTest)
target_link_libraries(ProjectTest PUBLIC ProjectLib)
target_link_libraries(CalculatorTest PUBLIC ProjectLib)
target_link_libraries(ParserTest PUBLIC ProjectLib)
