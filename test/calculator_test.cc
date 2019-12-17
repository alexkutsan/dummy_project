#include "calculator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace dev {
namespace testing {

class CalculatorTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  void TearDown() override {}
  dev::Calculator calculator_;
};

TEST_F(CalculatorTest, CheckUserInput_WrongPattern_ExpectFalse) {
  EXPECT_FALSE(calculator_.is_user_input_correct(""));
}

TEST_F(CalculatorTest, CheckUserInput_CorrectPattern_ExpectTrue) {
  EXPECT_TRUE(calculator_.is_user_input_correct("3 5 7.2 +"));
}

TEST_F(CalculatorTest,
       CalculateResultOfPlus_CorrectPattern_ExpectCorrectResult) {
  const std::string correct_input("3 5 7 +");
  ASSERT_TRUE(calculator_.is_user_input_correct(correct_input));
  calculator_.save_user_input(correct_input);
  const float correct_result = 15;
  EXPECT_EQ(correct_result, calculator_.calculate_result());
}

TEST_F(CalculatorTest,
       CalculateResultOfMinus_CorrectPattern_ExpectCorrectResult) {
  const std::string input("13 3 7.5 -");
  ASSERT_TRUE(calculator_.is_user_input_correct(input));
  calculator_.save_user_input(input);
  const float correct_result = 2.5;
  EXPECT_EQ(correct_result, calculator_.calculate_result());
}

TEST_F(CalculatorTest,
       CalculateResultOfMultiply_CorrectPattern_ExpectCorrectResult) {
  const std::string input("15 2 3 *");
  ASSERT_TRUE(calculator_.is_user_input_correct(input));
  calculator_.save_user_input(input);
  const float correct_result = 90;
  EXPECT_EQ(correct_result, calculator_.calculate_result());
}

TEST_F(CalculatorTest,
       CalculateResultOfDivision_CorrectPattern_ExpectCorrectResult) {
  const std::string input("45 3 5 /");
  ASSERT_TRUE(calculator_.is_user_input_correct(input));
  calculator_.save_user_input(input);
  const float correct_result = 3;
  EXPECT_EQ(correct_result, calculator_.calculate_result());
}

TEST_F(CalculatorTest,
       CalculateResultOfDivisionByZero_CorrectPattern_ExpectCorrectResult) {
  const std::string input("45 3 0 /");
  ASSERT_TRUE(calculator_.is_user_input_correct(input));
  calculator_.save_user_input(input);
  const float correct_result = 0;
  EXPECT_EQ(correct_result, calculator_.calculate_result());
}

}  // namespace testing
}  // namespace dev
