#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Calculator{

public:
    Calculator();

    double calculate(std::string input);
    std::string error() const;

private:

    void initOperators();
    void clear();
    bool parseInput(std::string input);
    bool intermediateCalculation(u_int operator_idx);
    bool isOperator(char oper);
    bool isNumber(double);
    int maxOperatorsPriority();

    std::vector<double> m_operands;
    std::vector<char> m_operators;
    std::unordered_map<char, u_char> m_availableOperators;
    std::string m_error;
};
