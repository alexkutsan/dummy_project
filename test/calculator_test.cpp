#include <gtest/gtest.h>

#include "../src/Calculator/include/calculator.h"

#include <iostream>

class CalculatorTest : public ::testing::Test {

public:
    Calculator calculator;
};

//// TDD + extreme programing
//// Polish notation calculator
//// basic design calc(std::sting) -> double

TEST_F(CalculatorTest, Init) {
    ASSERT_EQ(1, 1);
}

TEST_F(CalculatorTest, AddPositive) {
    ASSERT_EQ(calculator.calculate("2 3 +"), 5);
}

TEST_F(CalculatorTest, AddNegative) {
    ASSERT_EQ(calculator.calculate("-2 -3 +"), -5);
}

TEST_F(CalculatorTest, Substract) {
    ASSERT_EQ(calculator.calculate("5 2 -"), -3);
}

TEST_F(CalculatorTest, Multiply) {
    ASSERT_EQ(calculator.calculate("3 7 *"), 21);
}

TEST_F(CalculatorTest, Devide) {
    ASSERT_EQ(calculator.calculate("7 21 /"), 3);
}

TEST_F(CalculatorTest, MultiplyByZero) {
    ASSERT_EQ(calculator.calculate("21 0 *"), 0);
}

TEST_F(CalculatorTest, DevideByZero) {
    ASSERT_EQ(calculator.calculate("21 0 /"), 0);
    ASSERT_EQ(calculator.error(), "result is indefinite");
}

TEST_F(CalculatorTest, ComplexAdd) {
    ASSERT_EQ(calculator.calculate("2 3 6 + +"), 11);
}

TEST_F(CalculatorTest, ComplexPriorityOperation) {
    ASSERT_EQ(calculator.calculate("2 3 6 + *"), 18);
}

TEST_F(CalculatorTest, ComplexPriorityOperationMultiplyByZero) {
    ASSERT_EQ(calculator.calculate("2 3 0 + *"), 6);
}

TEST_F(CalculatorTest, ComplexPriorityOperationDevideByZero) {
    ASSERT_EQ(calculator.calculate("0 3 2 + /"), 0);
    ASSERT_EQ(calculator.error(), "division by zero is undefined");
}

TEST_F(CalculatorTest, SimbolNotSuported) {
    ASSERT_EQ(calculator.calculate("2 3 #"), 0);
    ASSERT_EQ(calculator.error(), "input simbol: # not supported!");
}
