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

TEST_F(ProjectTest, Simple_Operations) {
    EXPECT_EQ(15, project_.run("10 5 +"));
    EXPECT_EQ(5, project_.run("10 5 -"));
    EXPECT_EQ(50, project_.run("10 5 *"));
    EXPECT_EQ(2, project_.run("10 5 /"));
}

}  // namespace testing
}  // namespace dev
