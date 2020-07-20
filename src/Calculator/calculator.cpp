#include "include/calculator.h"
#include <iostream>
#include <algorithm>

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

    for (auto o : input) {
        if (isOperator(o)) {
            operators.push_back(o);
            return true;
        }

        operands.push_back(o);
        return true;
    }
    return false;
}

void Calculator::clear()
{
    operands.clear();
    operators.clear();
}


bool Calculator::isOperator(const char& oper) {
    return std::find(availableOperators.begin(), availableOperators.end(), oper) != availableOperators.end();
}
