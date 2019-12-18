#include "Calculator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

class CalculatorTest : public ::testing::Test {
 public:
  void SetUp() override { 
  }
  void TearDown() override {
    numbers_.reset();
    operators_.reset();
  }

  void PrepareTest(const std::initializer_list<float>& numbers,
                   const std::initializer_list<std::string>& operators) {
    numbers_.reset(new types::NumbersStack(numbers));
    operators_.reset(new types::OperatorsList(operators));
    calculator_.reset(new Calculator(std::move(numbers_),
                                     std::move(operators_)));
  }
  std::unique_ptr<dev::Calculator> calculator_;
  types::NumbersStackPtr numbers_; 
  types::OperatorsListPtr operators_;
};

TEST_F(CalculatorTest, CalculateAdd) {
  PrepareTest({10.0,20.0},{"+"});
  EXPECT_EQ(30.0,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDecrease) {
  PrepareTest({10.0,20.0},{"-"});
  EXPECT_EQ(10.0,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateMultiply) {
  PrepareTest({10.0,20.0},{"*"});
  EXPECT_EQ(200.0,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDiv) {
  PrepareTest({10.0,20.0},{"/"});
  EXPECT_EQ(2.0,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateComplex) {
  PrepareTest({10.0,20.0,30.0,40.0,80.0},{"+","*","-","/"});
  EXPECT_EQ(358.0,calculator_->calculate());
}

TEST_F(CalculatorTest, CalculateNoNumbers) {
  PrepareTest({},{"+","*","-","/"});
  EXPECT_EQ(types::kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateNoOperators) {
  PrepareTest({10.0,20.0},{});
  EXPECT_EQ(types::kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateNothing) {
  PrepareTest({},{});
  EXPECT_EQ(types::kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDivideZero) {
  PrepareTest({0.0,1.0},{"/"});
  EXPECT_EQ(types::kError,calculator_->calculate());
}

}  // namespace testing
}  // namespace dev
