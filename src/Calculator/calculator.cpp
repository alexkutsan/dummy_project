#include "include/calculator.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>

Calculator::Calculator()
{
}

double Calculator::calculate(std::string input)
{
    clear();

    for (auto token : tokenize(input)) {

        if (isNumber(token)) {
            m_tmp_operands.push(atof(token.c_str()));
            continue;
        }

        if (isOperator(token.at(0))) {
            auto res = calculateNext(popOperands(), token.at(0));

            if (!res) {
                return 0.0;
            }

            m_tmp_operands.push(res.value());
            continue;
        }

        m_error = "input simbol: " + token + " not supported!";
        return 0.0;
    }

    return m_tmp_operands.top();
}

std::string Calculator::error() const
{
    return m_error;
}

void Calculator::clear()
{
    m_tmp_operands = {};
    m_error.clear();
}

Calculator::operands Calculator::popOperands()
{
    if (m_tmp_operands.size() < min_operandsNumber) {
        m_error = "wrong input string!";
        return {};
    }

    auto op2 = m_tmp_operands.top();
    m_tmp_operands.pop();
    auto op1 = m_tmp_operands.top();
    m_tmp_operands.pop();

    return std::make_pair(op1, op2);
}

Calculator::result Calculator::calculateNext(operands operands, char oper)
{
    auto op1 = operands.first;
    auto op2 = operands.second;

    switch (oper) {

    case '*' :
        return op1 * op2;

    case '/' :
        if (op2 == 0) {
            m_error = "division by zero is undefined";
            return {};
        }
        return op1 / op2;

    case '+' :
        return op1 + op2;

    case '-' :
        return op1 - op2;

    default:
        return {};
    }
}

Calculator::tokens Calculator::tokenize(std::string input) const
{
    std::istringstream inputStream(input);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{inputStream},
                                    std::istream_iterator<std::string>());

    if (tokens.empty()) {
        return {};
    }

    return tokens;
}


bool Calculator::isOperator(char oper) const {
    return std::find(m_availableOperators.begin(), m_availableOperators.end(), oper) != m_availableOperators.end();
}

bool Calculator::isNumber(std::string token) const
{
    // consider negative numbers
    if (token.at(0) == '-') {
        token.erase(0, 1);
    }
    bool isDigit = !token.empty() &&
                    std::find_if(token.begin(),
                                 token.end(),
                                 [](unsigned char c) {
                                    return !std::isdigit(c);
                                    }
                                 ) == token.end();
    return isDigit;
}
