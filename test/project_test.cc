#include "project.h"
#include "constant.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Project project_;
};

TEST_F(ProjectTest, Run_int) {
    ASSERT_EQ(3, project_.run("1 2 +"));
}

TEST_F(ProjectTest, Run_double) {
    ASSERT_EQ(3.3, project_.run("1.3 2 +"));
}

TEST_F(ProjectTest, Run_long_expression_below_zero) {
    ASSERT_EQ(-1, project_.run("1 2 - 1 + 1 -"));
}

TEST_F(ProjectTest, Run_long_expression_below_complex_test) {
    ASSERT_EQ(21, project_.run("1 2 + 3 4 + *"));
}

TEST_F(ProjectTest, Run_long_expression_above_zero) {
    ASSERT_EQ(49, project_.run("1 2 + 4 + 7 *"));
}

//TEST_F(ProjectTest, Is_number_double) {
//    ASSERT_EQ(true, project_.is_number("1.3"));
//}

//TEST_F(ProjectTest, Is_number_int) {
//    ASSERT_EQ(true, project_.is_number("2"));
//}

//TEST_F(ProjectTest, Is_number_invalid) {
//    ASSERT_EQ(false, project_.is_number("asdas"));
//}

//TEST_F(ProjectTest, Sum_double) {
//    ASSERT_EQ(3.1, project_.sum(1.1, 2));
//}

//TEST_F(ProjectTest, Sum_int) {
//    ASSERT_EQ(5, project_.sum(2, 3));
//}

//TEST_F(ProjectTest, Devision_double) {
//    ASSERT_EQ(1.3, project_.division(2.6, 2));
//}

//TEST_F(ProjectTest, Devision_int) {
//    ASSERT_EQ(3, project_.division(6, 2));
//}

//TEST_F(ProjectTest, Devision_zero_devision) {
//    ASSERT_EQ(-1, project_.division(6, 0));
//}

//TEST_F(ProjectTest, Subtract_int) {
//    ASSERT_EQ(4, project_.subtract(6, 2));
//}

//TEST_F(ProjectTest, Subtract_double) {
//    ASSERT_EQ(4.2, project_.subtract(6.2, 2));
//}

//TEST_F(ProjectTest, Multiplication_double) {
//    ASSERT_EQ(2.4, project_.multiplication(1.2, 2));
//}

//TEST_F(ProjectTest, Multiplication_int) {
//    ASSERT_EQ(4, project_.multiplication(2, 2));
//}

// to do: test all error code output from project
TEST_F(ProjectTest, Run_error_code_test_NOT_CORRECT_COUNT_OF_OPERATION) {
    ASSERT_EQ(polish_notation_constant::ERROR_VALUE, project_.run("+ +"));
    ASSERT_EQ(static_cast<uint8_t>(polish_notation_constant::error_code::NOT_CORRECT_COUNT_OF_OPERATION),
              project_.get_error_code());
}

TEST_F(ProjectTest, Run_error_code_test_STACK_EMPTY) {
    ASSERT_EQ(polish_notation_constant::ERROR_VALUE, project_.run(""));
    ASSERT_EQ(static_cast<uint8_t>(polish_notation_constant::error_code::STACK_EMPTY),
              project_.get_error_code());
}

TEST_F(ProjectTest, Run_error_code_test_STACK_NOT_CORRECT_EXPRESSION) {
    ASSERT_EQ(polish_notation_constant::ERROR_VALUE, project_.run("2 * 3"));
    ASSERT_EQ(static_cast<uint8_t>(polish_notation_constant::error_code::NOT_CORRECT_EXPRESSION),
              project_.get_error_code());
}

}  // namespace testing
}  // namespace dev
