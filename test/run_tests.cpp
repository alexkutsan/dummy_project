#include "run.h"
#include "mock/irpncalculator_mock.h"
#include <gtest/gtest.h>

namespace dev
{
    namespace testing
    {
        using ::testing::Return;

        class MainTest : public ::testing::Test
        {
        public:
            void SetUp() override
            {
            }
            void TearDown() override
            {
            }
        };

        TEST_F(MainTest, Run_SUCCESS)
        {
            dev::MockIRPNCalculator project_mock;
            EXPECT_CALL(project_mock, run()).WillOnce(Return(0));
            auto res = run(project_mock);
            EXPECT_EQ(res, 0);
        }

        TEST_F(MainTest, Run_ERROR)
        {
            dev::MockIRPNCalculator project_mock;
            EXPECT_CALL(project_mock, run()).WillOnce(Return(1));
            auto res = run(project_mock);
            EXPECT_NE(res, 0);
        }

    }// namespace testing
}// namespace dev
