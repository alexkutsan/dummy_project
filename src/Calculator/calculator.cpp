#include "include/calculator.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>

Calculator::Calculator()
{
    std::cout << "Calculator created" << std::endl;
}

Calculator::~Calculator()
{
    std::cout << "Calculator destroied" << std::endl;
}

double Calculator::calculate(std::string input)
{
    clear();
    parseInput(input);

    if (operators.at(0) == '+') {
        return operands.at(0) + operands.at(1);
    }

    if (operators.at(0) == '-') {
        return operands.at(0) - operands.at(1);
    }

    if (operators.at(0) == '*') {
        return operands.at(0) * operands.at(1);
    }

    if (operators.at(0) == '/') {
        return operands.at(0) / operands.at(1);
    }

    return -1;
}

bool Calculator::parseInput(std::string input)
{
    // error handling should be implemented
    std::istringstream inputStream(input);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{inputStream},
                                     std::istream_iterator<std::string>());

    for (auto token : tokens) {
        if (isOperator(token.at(0)) && token.size() == 1) {
            operators.push_back(token.at(0));
            continue;
        }

        operands.push_back(atof(token.c_str()));
    }
    return true;
}

void Calculator::clear()
{
    operands.clear();
    operators.clear();
}


bool Calculator::isOperator(const char& oper) {
    return std::find(availableOperators.begin(), availableOperators.end(), oper) != availableOperators.end();
}
