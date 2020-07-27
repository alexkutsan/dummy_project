#include "include/calculator.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>

Calculator::Calculator()
{
}

double Calculator::calculate(std::string input)
{
    clear();

    std::istringstream inputStream(input);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{inputStream},
                                    std::istream_iterator<std::string>());

    for (auto token : tokens) {

        if (token.size() == 1 && isOperator(token.at(0))) {
            auto res = calculateNext(token.at(0));

            if (!res) {
                return 0.0;
            }

            m_tmp_operands.push(res.value());
            continue;
        }

        if (isNumber(token)) {
            m_tmp_operands.push(atof(token.c_str()));
            continue;
        }

        m_error = "input simbol: " + token + " not supported!";
        return false;
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

Calculator::result Calculator::calculateNext(char oper)
{
    if (!isOperator(oper)) {
        m_error = "operator: " + std::string{oper} + "not supported";
        return {};
    }

    if (m_tmp_operands.size() < min_operands_number) {
        m_error = "wrong input string!";
        return {};
    }

    auto op1 = m_tmp_operands.top();
    m_tmp_operands.pop();
    auto op2 = m_tmp_operands.top();
    m_tmp_operands.pop();

    switch (oper) {
    case '*' :
        return op1 * op2;
        break;

    case '/' :
        if (op1 == 0) {
            m_error = "result is indefinite";
            return {};
        }
        if (op2 == 0) {
            m_error = "division by zero is undefined";
            return {};
        }
        return op1 / op2;
        break;

    case '+' :
        return op1 + op2;
        break;

    case '-' :
        return op1 - op2;
        break;
    default:
        return {};
    }
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
