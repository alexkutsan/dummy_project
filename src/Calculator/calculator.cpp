#include "include/calculator.h"
#include <iostream>

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
    return -1;
}
