#include "project.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

//TODO: Add appropriate tests for each new component (Calculator / Parser)

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Project project_;
};

TEST_F(ProjectTest, ParseString_FAILURE) {
  EXPECT_FALSE(project_.parse_string(""));
  EXPECT_FALSE(project_.parse_string(" 5 4 3 2 "));
  EXPECT_FALSE(project_.parse_string(" + - = * "));
}

TEST_F(ProjectTest, ParseString_SUCCESS) {
  EXPECT_TRUE(project_.parse_string("5 5 +"));
  std::vector<int> expected_numbers = {5,5};
  std::vector<std::string> expected_operators = {"+"};
  EXPECT_EQ(expected_numbers, project_.get_numbers());
  EXPECT_EQ(expected_operators, project_.get_operators());
}

TEST_F(ProjectTest, CalculateNothing) {
  ASSERT_EQ(kError, project_.calculate());
}

TEST_F(ProjectTest, CalculateNoOperators) {
  ASSERT_FALSE(project_.parse_string("5 5"));
  EXPECT_EQ(kError, project_.calculate());
}

TEST_F(ProjectTest, CalculateNoNumbers) {
  ASSERT_FALSE(project_.parse_string("+ - / *"));
  EXPECT_EQ(kError, project_.calculate());
}

TEST_F(ProjectTest, CalculateAdd) {
  ASSERT_TRUE(project_.parse_string("5 5 +"));
  EXPECT_EQ(10, project_.calculate());
}

TEST_F(ProjectTest, CalculateDecrease) {
  ASSERT_TRUE(project_.parse_string("7 5 -"));
  EXPECT_EQ(-2, project_.calculate());
}

TEST_F(ProjectTest, CalculateMultiply) {
  ASSERT_TRUE(project_.parse_string("5 7 *"));
  EXPECT_EQ(35, project_.calculate());
}

TEST_F(ProjectTest, CalculateDivide) {
  ASSERT_TRUE(project_.parse_string("7 14 /"));
  EXPECT_EQ(2, project_.calculate());
}

TEST_F(ProjectTest, CalculateAddMultiple) {
  ASSERT_TRUE(project_.parse_string("14 7 3 4 + + +"));
  EXPECT_EQ(28, project_.calculate());
}

TEST_F(ProjectTest, CalculateSeveralOperations) {
  ASSERT_TRUE(project_.parse_string("4 4 4 4 + * -"));
  EXPECT_EQ(28, project_.calculate());
}

TEST_F(ProjectTest, CalculateSeveralOperationsDifferentPlacementOrder) {
  ASSERT_TRUE(project_.parse_string("1 2 + 4 * 3 +"));
  EXPECT_EQ(15, project_.calculate());
}

TEST_F(ProjectTest, CalculateDividingZero) {
  ASSERT_TRUE(project_.parse_string("0 1 /"));
  EXPECT_EQ(kError, project_.calculate());
}

}  // namespace testing
}  // namespace dev
