#pragma once

#include <string>
#include <array>
#include <stack>
#include <optional>
#include <utility>
#include <vector>

/**
 * @brief Polish notation calculator
 */

class Calculator{

public:
    Calculator();

    double calculate(std::string input);
    void clear();
    std::string error() const;

private:
    using result = std::optional<double>;
    using operands = std::pair<double, double>;
    using tokens = std::vector<std::string>;

private:
    operands popOperands();
    result calculateNext(operands operands, char oper);
    void handleOperandToken(const std::string& token);
    result handleOperatorToken(const std::string& token);

    tokens tokenize(const std::string& input) const;
    bool isOperator(const std::string& oper) const;
    bool isOperand(std::string token) const;

    std::stack<double> m_tmp_operands;
    std::string m_error;

    static constexpr std::array<char, 4> m_availableOperators{'*', '/', '+', '-'};
    static constexpr int min_operandsNumber{2};
};
