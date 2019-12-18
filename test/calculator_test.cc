#include "Calculator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

class CalculatorTest : public ::testing::Test {
 public:
  void SetUp() override { 
  }
  void TearDown() override {
    numbers_.reset();
    operators_.reset();
  }

  void PrepareTest(const std::initializer_list<int>& numbers,
                   const std::initializer_list<std::string>& operators) {
    numbers_.reset(new NumbersStack(numbers));
    operators_.reset(new OperatorsList(operators));
    calculator_.reset(new Calculator(std::move(numbers_),
                                     std::move(operators_)));
  }
  std::unique_ptr<dev::Calculator> calculator_;
  NumbersStackPtr numbers_; 
  OperatorsListPtr operators_;
};

TEST_F(CalculatorTest, CalculateAdd) {
  PrepareTest({10,20},{"+"});
  EXPECT_EQ(30,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDecrease) {
  PrepareTest({10,20},{"-"});
  EXPECT_EQ(10,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateMultiply) {
  PrepareTest({10,20},{"*"});
  EXPECT_EQ(200,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDiv) {
  PrepareTest({10,20},{"/"});
  EXPECT_EQ(2,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateComplex) {
  PrepareTest({10,20,30,40,80},{"+","*","-","/"});
  EXPECT_EQ(358,calculator_->calculate());
}

TEST_F(CalculatorTest, CalculateNoNumbers) {
  PrepareTest({},{"+","*","-","/"});
  EXPECT_EQ(kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateNoOperators) {
  PrepareTest({10,20},{});
  EXPECT_EQ(kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateNothing) {
  PrepareTest({},{});
  EXPECT_EQ(kError,calculator_->calculate());
}
TEST_F(CalculatorTest, CalculateDivideZero) {
  PrepareTest({0,1},{"/"});
  EXPECT_EQ(kError,calculator_->calculate());
}

}  // namespace testing
}  // namespace dev
