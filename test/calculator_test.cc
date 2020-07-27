#include "calculator.h"
#include "calculator_exception.h"

#include <gtest/gtest.h>

namespace dev {
namespace testing {

class CalculatorTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Calculator calculator_;
};

// 1. Basic operations

TEST_F(CalculatorTest, CalcAdd) {
  ASSERT_DOUBLE_EQ(3.0, calculator_.calc("1 2 +"));
}

TEST_F(CalculatorTest, CalcSub) {
  ASSERT_DOUBLE_EQ(-1.0, calculator_.calc("1 2 -"));
}

TEST_F(CalculatorTest, CalcMul) {
  ASSERT_DOUBLE_EQ(2.0, calculator_.calc("1 2 *"));
}

TEST_F(CalculatorTest, CalcDiv) {
  ASSERT_DOUBLE_EQ(0.5, calculator_.calc("1 2 /"));
}

// 2. Basic operations with double

TEST_F(CalculatorTest, CalcAdd2) {
  ASSERT_DOUBLE_EQ(4.0, calculator_.calc("1.5 2.5 +"));
}

TEST_F(CalculatorTest, CalcSub2) {
  ASSERT_DOUBLE_EQ(-1.0, calculator_.calc("1.5 2.5 -"));
}

TEST_F(CalculatorTest, CalcMul2) {
  ASSERT_DOUBLE_EQ(3.75, calculator_.calc("1.5 2.5 *"));
}

TEST_F(CalculatorTest, CalcDiv2) {
  ASSERT_DOUBLE_EQ(6.0, calculator_.calc("15.0 2.5 /"));
}

// 3. Complex operations

TEST_F(CalculatorTest, CalcComplex) {
  ASSERT_DOUBLE_EQ(2.0, calculator_.calc("1.5 2.5 + 2.0 /"));
}

TEST_F(CalculatorTest, CalcComplex2) {
  ASSERT_DOUBLE_EQ(-4.8, calculator_.calc("1.5 2.5 - 4.8 *"));
}

// 4. Divide by zero operation

TEST_F(CalculatorTest, CalcDivByZero) {
  EXPECT_THROW(calculator_.calc("1.5 0 /"), DivideByZeroException);
}

// 5. Mixing double and int

TEST_F(CalculatorTest, CalcMixDoubleInt) {
  ASSERT_DOUBLE_EQ(7.7, calculator_.calc("15.4 2 /"));
}

// 6. Test custom exceptions

TEST_F(CalculatorTest, CalcInvalidOperand) {
  EXPECT_THROW(calculator_.calc("a b +"), InvalidOperandException);
}

TEST_F(CalculatorTest, CalcOperandOutOfRange) {
  EXPECT_THROW(calculator_.calc("7.63918e-313 1 +"), OperandOutOfRangeException);
}

TEST_F(CalculatorTest, CalcInvalidOperator) {
  EXPECT_THROW(calculator_.calc("5 6 ^"), InvalidOperatorException);
}

TEST_F(CalculatorTest, CalcInvalidExpression) {
  EXPECT_THROW(calculator_.calc("5 6 + 7"), InvalidExpressionException);
}

TEST_F(CalculatorTest, CalcInvalidExpression2) {
  EXPECT_THROW(calculator_.calc("5 6 + *"), InvalidExpressionException);
}

}  // namespace testing
}  // namespace dev
