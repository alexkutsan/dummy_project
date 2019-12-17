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

TEST_F(ProjectTest, WithoutOperations) {
   ASSERT_EQ(1, project_.run("1"));
}

TEST_F(ProjectTest, SimpleAdd) {
   ASSERT_EQ(2, project_.run("1 1 +"));
}

TEST_F(ProjectTest, SimpleSub) {
   ASSERT_EQ(0, project_.run("1 1 -"));
}

TEST_F(ProjectTest, SimpleMul) {
   ASSERT_EQ(4, project_.run("2 2 *"));
}

TEST_F(ProjectTest, SimpleDiv) {
   ASSERT_EQ(2, project_.run("4 2 /"));
}

TEST_F(ProjectTest, DubleAdd) {
   ASSERT_EQ(6, project_.run("1 2 + 3 +"));
   ASSERT_EQ(6, project_.run("1 2 3 + +"));
}

TEST_F(ProjectTest, TripleAdd) {
   ASSERT_EQ(10, project_.run("1 2 3 4 + + +"));
   ASSERT_EQ(10, project_.run("1 2 3 + 4 + +"));
   ASSERT_EQ(10, project_.run("1 2 3 + + 4 +"));
   ASSERT_EQ(10, project_.run("1 2 + 3 + 4 +"));
}

class CalcTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  PolishCalcComponent::PolishCalc calc_;
};

TEST_F(CalcTest, LogicErrorExtraOperator) {
   PolishCalcComponent::value_t res = -1.0;
   ASSERT_EQ(PolishCalcComponent::CalcError::LOGIC_ERROR, calc_.process("1 1 + +", res));
   ASSERT_EQ(-1.0, res);
}

TEST_F(CalcTest, LogicErrorNotEnoughValues) {
   PolishCalcComponent::value_t res = -1.0;
   ASSERT_EQ(PolishCalcComponent::CalcError::LOGIC_ERROR, calc_.process("1 +", res));
   ASSERT_EQ(-1.0, res);
}

TEST_F(CalcTest, LogicErrorNoValues) {
   PolishCalcComponent::value_t res = -1.0;
   ASSERT_EQ(PolishCalcComponent::CalcError::LOGIC_ERROR, calc_.process("+", res));
   ASSERT_EQ(-1.0, res);
}

TEST_F(CalcTest, LogicErrorUndefinedResult) {
   PolishCalcComponent::value_t res = -1.0;
   ASSERT_EQ(PolishCalcComponent::CalcError::LOGIC_ERROR, calc_.process("1 1", res));
   ASSERT_EQ(-1.0, res);
}

TEST_F(CalcTest, ParseErrorEmptyInput) {
   PolishCalcComponent::value_t res = -1.0;
   ASSERT_EQ(PolishCalcComponent::CalcError::PARSE_ERROR, calc_.process("", res));
   ASSERT_EQ(-1.0, res);
}

}  // namespace testing
}  // namespace dev
