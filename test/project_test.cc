#include "project.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

namespace {
  const auto kError = std::numeric_limits<float>::min();
}

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Project project_;
};

TEST_F(ProjectTest, ParseString_FAILURE) {
  EXPECT_EQ(kError, project_.run(""));
  EXPECT_EQ(kError, project_.run(" 5 4 3 2 "));
  EXPECT_EQ(kError, project_.run(" + - = * "));
}

TEST_F(ProjectTest, ParseString_SUCCESS) {
  EXPECT_TRUE(project_.run("5 5 +"));
}

TEST_F(ProjectTest, CalculateNothing) {
  EXPECT_EQ(kError, project_.run(""));
}

TEST_F(ProjectTest, CalculateNoOperators) {
  EXPECT_EQ(kError, project_.run("5 5"));
}

TEST_F(ProjectTest, CalculateNoNumbers) {
  EXPECT_EQ(kError, project_.run("+ - / *"));
}

TEST_F(ProjectTest, CalculateAdd) {
  EXPECT_EQ(10, project_.run("5 5 +"));
}

TEST_F(ProjectTest, CalculateDecrease) {
  EXPECT_EQ(-2, project_.run("7 5 -"));
}

TEST_F(ProjectTest, CalculateMultiply) {
  EXPECT_EQ(35, project_.run("5 7 *"));
}

TEST_F(ProjectTest, CalculateDivide) {
  EXPECT_EQ(2, project_.run("7 14 /"));
}

TEST_F(ProjectTest, CalculateAddMultiple) {
  EXPECT_EQ(28, project_.run("14 7 3 4 + + +"));
}

TEST_F(ProjectTest, CalculateSeveralOperations) {
  EXPECT_EQ(28, project_.run("4 4 4 4 + * -"));
}

TEST_F(ProjectTest, CalculateSeveralOperationsDifferentPlacementOrder) {
  EXPECT_EQ(15, project_.run("1 2 + 4 * 3 +"));
}

TEST_F(ProjectTest, CalculateDividingZero) {
  EXPECT_EQ(kError, project_.run("0 1 /"));
}

}  // namespace testing
}  // namespace dev
