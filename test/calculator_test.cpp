#include <gtest/gtest.h>

#include "../src/Calculator/include/calculator.h"

class CalculatorTest : public ::testing::Test {

public:
    Calculator calculator;
};

//// TDD
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
    ASSERT_EQ(calculator.calculate("5 2 -"), 3);
}

TEST_F(CalculatorTest, Multiply) {
    ASSERT_EQ(calculator.calculate("3 7 *"), 21);
}

TEST_F(CalculatorTest, Devide) {
    ASSERT_EQ(calculator.calculate("21 7 /"), 3);
}

TEST_F(CalculatorTest, MultiplyWithZero) {
    ASSERT_EQ(calculator.calculate("21 0 *"), 0);
}

TEST_F(CalculatorTest, DevideWithZero) {
    ASSERT_EQ(calculator.calculate("21 0 /"), -1);
}

// Add complex (multiple operand) functions/tests
