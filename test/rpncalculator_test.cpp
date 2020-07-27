#include "rpncalculator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

namespace dev
{
    namespace testing
    {

        class RPNCalculatorTest : public ::testing::Test
        {
        public:
            void SetUp() override
            {
            }
            void TearDown() override
            {
            }

        public:
            dev::RPNCalculator m_calculator;
        };

        TEST_F(RPNCalculatorTest, RunEmptyString)
        {
            m_calculator.addExpression("");
            ASSERT_EQ(0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, OneNumber)
        {
            m_calculator.addExpression("1");
            ASSERT_EQ(1.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcAdd)
        {
            m_calculator.addExpression("1 4 +");
            ASSERT_DOUBLE_EQ(5.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcSub)
        {
            m_calculator.addExpression("1 4 -");
            ASSERT_DOUBLE_EQ(-3.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcMul)
        {
            m_calculator.addExpression("1 4 *");
            ASSERT_DOUBLE_EQ(4.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcDiv)
        {
            m_calculator.addExpression("1 4 /");
            ASSERT_DOUBLE_EQ(0.25, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcAddNegative)
        {
            m_calculator.addExpression("1 -4 +");
            ASSERT_DOUBLE_EQ(-3.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcSubNegative)
        {
            m_calculator.addExpression("1 -4 -");
            ASSERT_DOUBLE_EQ(5.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcMulNegative)
        {
            m_calculator.addExpression("1 -4 *");
            ASSERT_DOUBLE_EQ(-4.0, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcDivNegative)
        {
            m_calculator.addExpression("-1 -4 /");
            ASSERT_DOUBLE_EQ(0.25, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcComplex)
        {
            m_calculator.addExpression("4 12 3 + * 2 / 5 5 + * 100 2 * - 2 /");
            ASSERT_DOUBLE_EQ(50, m_calculator.run());
        }

        TEST_F(RPNCalculatorTest, CalcDivByZero)
        {
            m_calculator.addExpression("1 0 /");
            EXPECT_THROW(m_calculator.run(), std::logic_error);
        }

        TEST_F(RPNCalculatorTest, CalcTooFewNumbers)
        {
            m_calculator.addExpression("1 /");
            EXPECT_THROW(m_calculator.run(), std::underflow_error);
        }

        TEST_F(RPNCalculatorTest, CalcTooManyOperators)
        {
            m_calculator.addExpression("1 2 / /");
            EXPECT_THROW(m_calculator.run(), std::underflow_error);
        }

        TEST_F(RPNCalculatorTest, CalcWrongExpression)
        {
            m_calculator.addExpression("+ - / /");
            EXPECT_THROW(m_calculator.run(), std::underflow_error);
        }

        TEST_F(RPNCalculatorTest, CalcStackOverFlow)
        {
            m_calculator.addExpression("0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4");
            EXPECT_THROW(m_calculator.run(), std::overflow_error);
        }

    }// namespace testing
}// namespace dev
