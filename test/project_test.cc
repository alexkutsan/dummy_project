#include "project.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

#include "Token.h"
#include "Stack.h"
#include "Parser.h"
#include "executor.h"

namespace dev {
namespace testing {

/*
 * List of tests:
 * -ввод одной цифры
 * -ввод однонго символа
 * -ввод одной операции
 * -ввод неправильной последовательности + 2 3
 * -ввод одних символов
 * -ввод дробных чисел
 * -ряд тестов с простыми операциями + - * /
 * -ввод отрицательных чисел
 * -такая комбинация чисел при которой получается отрицательный результат
 * -сложное вырежение. 15 7 1 1 + - / 3 \* 2 1 1 + + -
 * -пустая строка
 * -нет операции(одни числа)
 * -деление на 0
 * -лишнее операнды
 * -числа overflow
 * -попробовать вызвать exec с вызовом программы с параметрами.
 *
 * 5 2 \* 2 / 6.5 -
 *
 * вопрос.
 * хороший тест вызов одной функции на одну строку
 * не пишем специальных функций для тестов.
 *
 * */

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override;
  void TearDown() override;
  dev::Project project_;
};

void ProjectTest::SetUp()
{
    std::cout << "SetUp" << std::endl;
}

void ProjectTest::TearDown()
{
    std::cout << "TearDown" << std::endl;
}

TEST_F(ProjectTest, Run) {

    std::cout << "lalala" << std::endl;
  ASSERT_EQ(0, project_.run());
}

//Token test start
TEST_F(ProjectTest, TokenNumber) {
    constexpr double test_number = -9.985;
    Token t(test_number);
    ASSERT_DOUBLE_EQ(test_number, t.getNumber());
    ASSERT_EQ(true, t.is_number());
    ASSERT_EQ(TOper::NONE, t.getOperand());
}

TEST_F(ProjectTest, TokenOperation) {
    TOper::Operand test_operation = TOper::DIV;
    Token t(test_operation);
    ASSERT_EQ(0, t.getNumber());
    ASSERT_EQ(false, t.is_number());
    ASSERT_EQ(test_operation, t.getOperand());
}

TEST_F(ProjectTest, TokenComplexConstructor) {
    constexpr double test_number = -9.985;
    Token t(true, TOper::ADD, test_number);
    ASSERT_DOUBLE_EQ(test_number, t.getNumber());
    ASSERT_EQ(true, t.is_number());
    ASSERT_EQ(TOper::NONE, t.getOperand());

    Token t2(false, TOper::ADD, test_number);
    ASSERT_EQ(0, t2.getNumber());
    ASSERT_EQ(false, t2.is_number());
    ASSERT_EQ(TOper::ADD, t2.getOperand());
}
//Token test end

//Stack test start
TEST_F(ProjectTest, Stack) {
    std::vector<Token> tk;
    tk.push_back(Token(true, TOper::NONE, 3));
    tk.push_back(Token(true, TOper::NONE, 2));
    tk.push_back(Token(false, TOper::ADD, 0));
    tk.push_back(Token(true, TOper::NONE, 1));
    tk.push_back(Token(false, TOper::SUB, 0));
    Stack stk(tk);

    int rc = 0;
    Token t = stk.pop(rc);
    ASSERT_EQ(1, rc);
    ASSERT_EQ(1, t.is_number());
    ASSERT_EQ(t.getNumber(), 3);
    ASSERT_EQ(4, stk.getSize());

    t = stk.pop(rc);
    ASSERT_EQ(1, rc);
    ASSERT_EQ(1, t.is_number());
    ASSERT_EQ(t.getNumber(), 2);
    ASSERT_EQ(stk.getSize(), 3);

    t = stk.pop(rc);

//    std::cout << "test " << t.is_number() << std::endl;
//    std::cout << t.getNumber() << std::endl;
//    std::cout << t.getOperand() << std::endl;

    ASSERT_EQ(1, rc);
    ASSERT_EQ(0, t.is_number());
    ASSERT_EQ(t.getOperand(), TOper::ADD);
    ASSERT_EQ(stk.getSize(), 2);

    t = stk.pop(rc);
    ASSERT_EQ(1, rc);
    ASSERT_EQ(1, t.is_number());
    ASSERT_EQ(t.getNumber(), 1);
    ASSERT_EQ(stk.getSize(), 1);

    t = stk.pop(rc);
    ASSERT_EQ(1, rc);
    ASSERT_EQ(false, t.is_number());
    ASSERT_EQ(t.getOperand(), TOper::SUB);
    ASSERT_EQ(stk.getSize(), 0);

    t = stk.pop(rc);
    ASSERT_EQ(0, rc);
}
//Stack test end

//Parser test start
TEST_F(ProjectTest, Parser) {
    std::vector<std::string> customLine;
    customLine.push_back(std::string("638763"));
    customLine.push_back(std::string("0.2121"));
    customLine.push_back(std::string("-0.212"));
    customLine.push_back(std::string("-8678"));
    customLine.push_back(std::string("-"));
    customLine.push_back(std::string("+"));
    customLine.push_back(std::string("/"));
    customLine.push_back(std::string("*"));
    customLine.push_back(std::string("-0,212"));
    //can`t check wrong input because of try catch =((

    Parser p1(customLine);
    p1.parse();

    std::vector<Token> resultTokins(p1.getTokens());
    ASSERT_EQ(resultTokins[0].getNumber(), 638763);
    ASSERT_DOUBLE_EQ(resultTokins[1].getNumber(), 0.2121);
    ASSERT_DOUBLE_EQ(resultTokins[2].getNumber(), -0.212);
    ASSERT_EQ(resultTokins[3].getNumber(), -8678);
    ASSERT_EQ(resultTokins[4].getOperand(), TOper::SUB);
    ASSERT_EQ(resultTokins[5].getOperand(), TOper::ADD);
    ASSERT_EQ(resultTokins[6].getOperand(), TOper::DIV);
    ASSERT_EQ(resultTokins[7].getOperand(), TOper::MUL);
    ASSERT_DOUBLE_EQ(resultTokins[2].getNumber(), -0.212);
}
//Parser test end


//Calculator test start
TEST_F(ProjectTest, simpleAdd) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("+"));

    ASSERT_DOUBLE_EQ(execute(sources), 7);
}

TEST_F(ProjectTest, simpleSub) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("-"));

    ASSERT_DOUBLE_EQ(execute(sources), 3);
}

TEST_F(ProjectTest, simpleMul) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("*"));

    ASSERT_DOUBLE_EQ(execute(sources), 10);
}

TEST_F(ProjectTest, simpleDiv) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("/"));

    ASSERT_DOUBLE_EQ(execute(sources), 2.5);
}

TEST_F(ProjectTest, mediumRear) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("/"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("*"));
    sources.push_back(std::string("1"));
    sources.push_back(std::string("-"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("*"));

    ASSERT_DOUBLE_EQ(execute(sources), 8);
}

TEST_F(ProjectTest, wrongImput) {
    std::vector <std::string> sources;
    sources.push_back(std::string("5"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("/"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("*"));
    sources.push_back(std::string("1"));
    sources.push_back(std::string("-"));
    sources.push_back(std::string("2"));
    sources.push_back(std::string("H"));

    ASSERT_THROW(execute(sources), std::invalid_argument);
}

//Calculator test end

}  // namespace testing
}  // namespace dev
