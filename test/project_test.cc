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

TEST_F(ProjectTest, Run) {
  ASSERT_EQ(0, project_.run());
}

// TDD
// basic design calc(std::sting) -> double

TEST_F(ProjectTest, AddPositive) {
    ASSERT_EQ(project_.calc("2 3 +"), 5);
}

TEST_F(ProjectTest, AddNegative) {
    ASSERT_EQ(project_.calc("-2 -3 +"), -5);
}

TEST_F(ProjectTest, Substract) {
    ASSERT_EQ(project_.calc("5 2 -"), 3);
}

TEST_F(ProjectTest, Multiply) {
    ASSERT_EQ(project_.calc("3 7 *"), 21);
}

TEST_F(ProjectTest, Devide) {
    ASSERT_EQ(project_.calc("21 7 /"), 3);
}

TEST_F(ProjectTest, MultiplyWithZero) {
    ASSERT_EQ(project_.calc("21 0 *"), 0);
}

TEST_F(ProjectTest, DevideWithZero) {
    ASSERT_EQ(project_.calc("21 0 /"), -1);
}


}  // namespace testing
}  // namespace dev
