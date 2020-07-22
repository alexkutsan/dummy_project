#include "include/calculator.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>

Calculator::Calculator()
{
    initOperators();
}

double Calculator::calculate(std::string input)
{
    clear();

    if (!parseInput(input)) {
        return 0.0;
    }

    for (int priority = maxOperatorsPriority(); priority >= 0; priority--) {
        for (std::size_t currentOperatorIndex = 0;
             currentOperatorIndex < m_operators.size();
             currentOperatorIndex++) {
            if (operatorPriority(m_operators.at(currentOperatorIndex)) == priority) {
                if (!intermediateCalculation(currentOperatorIndex)) {
                    return 0.0;
                }
                currentOperatorIndex -= 1;
            }
        }
    }

    return m_operands.front();
}

std::string Calculator::error() const
{
    return m_error;
}

bool Calculator::parseInput(std::string input)
{
    std::istringstream inputStream(input);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{inputStream},
                                     std::istream_iterator<std::string>());

    for (auto token : tokens) {

        if (token.size() == 1 && isOperator(token.at(0))) {
            m_operators.push_back(token.at(0));
            continue;
        }

        if (isNumber(token)) {
            m_operands.push_back(atof(token.c_str()));
            continue;
        }

        m_error = "input simbol: " + token + " not supported!";
        return false;
    }

    if (m_operands.size() - 1 != m_operators.size()) {
        m_error = "input format error! number of operands and number of operators mismach!";
        return false;
    }

    return true;
}

void Calculator::clear()
{
    m_operands = {};
    m_operators = {};
    m_error.clear();
}


bool Calculator::isOperator(char oper) {
    bool Ok = m_availableOperators.find(oper) != m_availableOperators.end();
    return Ok;
}

bool Calculator::isNumber(std::string token)
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

bool Calculator::intermediateCalculation(u_int operator_idx) {

    auto oper = m_operators.at(operator_idx);
    auto op1 = m_operands.at(operator_idx);
    auto op2 = m_operands.at(operator_idx + 1);

    double tmp_res{0.0};

    switch (oper) {

        case '*' :
            tmp_res = op1 * op2;
            break;

        case '/' :
            if (op2 == 0) {
                m_error = "division by zero is undefined";
                return false;
            }
            tmp_res = op1 / op2;
            break;

        case '+' :
            tmp_res = op1 + op2;
            break;

        case '-' :
            tmp_res = op1 - op2;
            break;

        default:
            m_error = "Operator not implemented!";
            return false;
    }

    m_operators.erase(m_operators.begin() + operator_idx);
    m_operands[operator_idx] = tmp_res;
    m_operands.erase(m_operands.begin() + operator_idx + 1);

    return true;
}

void Calculator::initOperators()
{
    m_availableOperators.insert({'*', 1});
    m_availableOperators.insert({'/', 1});
    m_availableOperators.insert({'+', 0});
    m_availableOperators.insert({'-', 0});
}

int Calculator::maxOperatorsPriority()
{
    using u_map_type = decltype(m_availableOperators)::value_type;
    auto pr = std::max_element
    (
        std::begin(m_availableOperators), std::end(m_availableOperators),
        [] (const u_map_type & p1, const u_map_type & p2) {
            return p1.second < p2.second;
        }
    );
    return pr->first;
}

int Calculator::operatorPriority(const char &oper)
{
    return m_availableOperators.at(oper);
}
