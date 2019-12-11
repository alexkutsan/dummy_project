#include "project.h"
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

TEST_F(ProjectTest, ParseString) {
  ASSERT_FALSE(project_.parse_string(""));
  EXPECT_TRUE(project_.parse_string("5 5 +"));
  std::vector<int> expected_numbers = {5,5};
  std::vector<std::string> expected_operators = {"+"};
  EXPECT_EQ(expected_numbers, project_.get_numbers());
  EXPECT_EQ(expected_operators, project_.get_operators());
}

TEST_F(ProjectTest, CalculateNothing) {
  ASSERT_EQ(std::numeric_limits<int>::min(), project_.calculate());
}

TEST_F(ProjectTest, CalculateNoOperators) {
  ASSERT_TRUE(project_.parse_string("5 5"));
  EXPECT_EQ(std::numeric_limits<int>::min(), project_.calculate());
}

TEST_F(ProjectTest, CalculateNoNumbers) {
  ASSERT_TRUE(project_.parse_string("+ - / *"));
  EXPECT_EQ(std::numeric_limits<int>::min(), project_.calculate());
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

}  // namespace testing
}  // namespace dev
