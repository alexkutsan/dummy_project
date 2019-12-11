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

TEST_F(ProjectTest, Run_Basic) {
  ASSERT_EQ(0, project_.run());
  ASSERT_EQ(10, project_.run("10"));
  ASSERT_EQ(10, project_.run("10 4"));
}

TEST_F(ProjectTest, Simple_Operations) {
    ASSERT_EQ(15, project_.run("10 5 +"));
    ASSERT_EQ(5, project_.run("10 5 -"));
    ASSERT_EQ(50, project_.run("10 5 *"));
    ASSERT_EQ(2, project_.run("10 5 /"));
}

TEST_F(ProjectTest, Simple_Operations_Float) {
    ASSERT_NEAR(15.2, project_.run("10.1 5.1 +"), 0.01);
    ASSERT_NEAR(5, project_.run("10.1 5.1 -"), 0.01);
    ASSERT_NEAR(51.51, project_.run("10.1 5.1 *"), 0.01);
    ASSERT_NEAR(2.02, project_.run("10.1 5 /"), 0.01);
}

TEST_F(ProjectTest, Simple_Operations_Exceptions) {
    ASSERT_THROW(project_.run("a"), std::exception);
    ASSERT_THROW(project_.run("a a"), std::exception);
    ASSERT_THROW(project_.run("+"), std::exception);
    ASSERT_THROW(project_.run("10 +"), std::exception);
}

TEST_F(ProjectTest, Simple_Operations_Complex) {
    EXPECT_EQ(17, project_.run("10 5 + 2 +"));
    EXPECT_EQ(7, project_.run("10 5 2 +"));
}

//TODO:
//  Increase coverage

}  // namespace testing
}  // namespace dev
