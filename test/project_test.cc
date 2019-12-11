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
        ASSERT_TRUE(project_.isOperator(op));
    }
}


TEST_F(ProjectTest, isOperatorInvalidCases) {
    const std::set<std::string> operators{"2", " ", "", "----"};
    for(const auto & op : operators) {
        ASSERT_FALSE(project_.isOperator(op));
    }
}

TEST_F(ProjectTest, applyOperationDivision) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(divide, operands);
    ASSERT_FLOAT_EQ(2.0, operands.front());
}

TEST_F(ProjectTest, applyOperationMultiply) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(multiply, operands);
    ASSERT_FLOAT_EQ(8.0, operands.front());
}

TEST_F(ProjectTest, applyOperationPlus) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(plus, operands);
    ASSERT_FLOAT_EQ(6.0, operands.front());
}

TEST_F(ProjectTest, applyOperationMinus) {
    std::vector<double> operands{4, 2};
    project_.applyOperation(minus, operands);
    ASSERT_FLOAT_EQ(2.0, operands.front());
}

}  // namespace testing
}  // namespace dev
