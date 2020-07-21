#include "calculator.h"

#include <gtest/gtest.h>

namespace dev {
namespace testing {

class CalculatorTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  Calculator calc_;
};

TEST_F(CalculatorTest, Add) {
  ASSERT_DOUBLE_EQ(7.0, calc_.evaluate("5 2 +"));
}

TEST_F(CalculatorTest, Subtract) {
  ASSERT_DOUBLE_EQ(3.0, calc_.evaluate("5 2 -"));
}

TEST_F(CalculatorTest, SubtractNegative) {
  ASSERT_DOUBLE_EQ(-3.0, calc_.evaluate("2 5 -"));
}

TEST_F(CalculatorTest, Multiply) {
  ASSERT_DOUBLE_EQ(10.0, calc_.evaluate("5 2 *"));
}

TEST_F(CalculatorTest, CalcDiv) {
  ASSERT_DOUBLE_EQ(2.5, calc_.evaluate("5 2 /"));
}

TEST_F(CalculatorTest, AddFloat) {
  ASSERT_DOUBLE_EQ(5.0, calc_.evaluate("2.5 2.5 +"));
}

TEST_F(CalculatorTest, SubFloat) {
  ASSERT_DOUBLE_EQ(-1.0, calc_.evaluate("1.5 2.5 -"));
}

TEST_F(CalculatorTest, MultFloat) {
  ASSERT_DOUBLE_EQ(6.25, calc_.evaluate("2.5 2.5 *"));
}

TEST_F(CalculatorTest, Divfloat) {
  ASSERT_DOUBLE_EQ(6.0, calc_.evaluate("15.0 2.5 /"));
}

TEST_F(CalculatorTest, MultipleOperator1) {
  ASSERT_DOUBLE_EQ(2.25, calc_.evaluate("1.5 3 + 2.0 /"));
}

TEST_F(CalculatorTest, MultipleOperator2) {
  ASSERT_DOUBLE_EQ(0, calc_.evaluate("2.5 2.5 - 4.0 *"));
}

}  // namespace testing
}  // namespace dev