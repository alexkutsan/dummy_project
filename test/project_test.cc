#include "project.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace dev {
namespace testing {

static const std::string plus = "+";
static const std::string minus = "-";
static const std::string multiply = "*";
static const std::string divide = "/";

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Project project_;
};

TEST_F(ProjectTest, isOperatorValidCases) {
    const std::set<std::string> operators{plus, minus, multiply, divide};
    for(const auto & op : operators) {
        EXPECT_TRUE(project_.isOperator(op));
    }
}

TEST_F(ProjectTest, isOperatorInvalidCases) {
    const std::set<std::string> operators{"2", " ", "", "----"};
    for(const auto & op : operators) {
        EXPECT_FALSE(project_.isOperator(op));
    }
}

TEST_F(ProjectTest, applyOperationDivision) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(divide, operands);
    EXPECT_FLOAT_EQ(2.0, operands.front());
}

TEST_F(ProjectTest, applyOperationMultiply) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(multiply, operands);
    EXPECT_FLOAT_EQ(8.0, operands.front());
}

TEST_F(ProjectTest, applyOperationPlus) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(plus, operands);
    EXPECT_FLOAT_EQ(6.0, operands.front());
}

TEST_F(ProjectTest, applyOperationMinus) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(minus, operands);
    EXPECT_FLOAT_EQ(2.0, operands.front());
}

TEST_F(ProjectTest, baseProcessArgumentsTest) {
    std::vector<std::string> args{"4", "2", "*", "7", "+"};
    const auto & result = project_.processArguments(args);
    ASSERT_EQ(1, result.size());
    EXPECT_FLOAT_EQ(15, result.back());
}

TEST_F(ProjectTest, baseProcessInputTest) {
    std::string input{"4 2 * 7 +"};
    const auto & result = project_.processInput(input);
    EXPECT_EQ(5, result.size());
}

TEST_F(ProjectTest, baseProcessTest) {
    std::string input{"4 2 * 7 +"};
    const auto & result = project_.process(input);
    ASSERT_EQ(1, result.size());
    EXPECT_FLOAT_EQ(15, result.back());
}

}  // namespace testing
}  // namespace dev
