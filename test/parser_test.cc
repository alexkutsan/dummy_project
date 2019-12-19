#include "Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace dev {
namespace testing {

class ParserTest : public ::testing::Test {
 protected:
  dev::Parser parser_;
};

TEST_F(ParserTest, ParseString_Add) {
  EXPECT_TRUE(parser_.parse("5 5 +"));
}
TEST_F(ParserTest, ParseString_Dec) {
  EXPECT_TRUE(parser_.parse("5 5 -"));
}
TEST_F(ParserTest, ParseString_Div) {
  EXPECT_TRUE(parser_.parse("5 5 /"));
}
TEST_F(ParserTest, ParseString_Mul) {
  EXPECT_TRUE(parser_.parse("5 5 *"));
}
TEST_F(ParserTest, ParseString_Complex) {
  EXPECT_TRUE(parser_.parse("5 5 4 3 * - +"));
}

TEST_F(ParserTest, ParseString_ComplexFAIL) {
  EXPECT_FALSE(parser_.parse("5 5 4 3 * - + *"));
}
TEST_F(ParserTest, ParseString_ParseNothing) {
  EXPECT_FALSE(parser_.parse(""));
}
TEST_F(ParserTest, ParseString_ParseNumbersOnly) {
  EXPECT_FALSE(parser_.parse(" 5 4 3 2 "));
}
TEST_F(ParserTest, ParseString_ParseOperatorsOnly) {
  EXPECT_FALSE(parser_.parse(" + - = * "));
}

}  // namespace testing
}  // namespace dev
