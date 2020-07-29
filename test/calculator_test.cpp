#include "project.h"
#include "polishNotationCalc.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev
{
    namespace testing
    {

        class CalculatorTest : public ::testing::Test
        {
        public:
            void SetUp() override {}
            void TearDown() override {}
            dev::PolishCalc project_;
        };
        TEST_F(CalculatorTest, BasicOPTestWithInt)
        {
            EXPECT_EQ(7, project_.calc("5 2 +"));
        }
        TEST_F(CalculatorTest, BasicOPTestWithDouble)
        {
            EXPECT_EQ(7.8, project_.calc("5.5 2.3 +"));
        }
        TEST_F(CalculatorTest, MissingOperand)
        {
            EXPECT_ANY_THROW(project_.calc("5 +"));
        }
        TEST_F(CalculatorTest, MissingOperator)
        {
            EXPECT_ANY_THROW(project_.calc("5 2"));
        }
        TEST_F(CalculatorTest, EmptyString)
        {
            EXPECT_ANY_THROW(project_.calc(""));
        }
        TEST_F(CalculatorTest, DivideByZero)
        {
            EXPECT_ANY_THROW(project_.calc("7 0 /"));
          
        }
        TEST_F(CalculatorTest, PerformComplexOpeartions)
        {
            EXPECT_EQ(405, project_.calc("50 31 + 10 5 - * "));
        }

        TEST_F(CalculatorTest, MixingDoubleAndInt)
        {
            auto res = (int)project_.calc("12.5 3 / ");
            EXPECT_EQ(4, res);
        }
    }
}