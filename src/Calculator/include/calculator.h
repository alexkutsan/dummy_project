#pragma once

#include <string>
#include <vector>

class Calculator{

public:
    Calculator();
    ~Calculator();

    double calculate(std::string input);

private:
    bool parseInput(std::string input);
    void clear();
    bool isOperator(const char& oper);

    std::vector<double> operands;
    std::vector<char> operators;
    const std::vector<char> availableOperators{'+', '-', '*', '/'};
};
