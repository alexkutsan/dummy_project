#include <gtest/gtest.h>
#include "utils.h"

TEST(UtilsTest, CheckUserInput_WrongPattern_ExpectFalse) {
    EXPECT_FALSE(is_user_input_correct(""));
}

TEST(UtilsTest, CheckUserInput_CorrectPattern_ExpectTrue) {
    EXPECT_TRUE(is_user_input_correct("3 5 7.2 +"));
}
