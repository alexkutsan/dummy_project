#pragma once

#include <string>
#include <array>
#include <stack>
#include <optional>

class Calculator{

    using result = std::optional<double>;

public:
    Calculator();

    double calculate(std::string input);
    std::string error() const;

private:
    void clear();
    result calculateNext(char oper);

    bool isOperator(char oper) const;
    bool isNumber(std::string token) const;

    std::stack<double> m_tmp_operands;
    std::string m_error;

    static constexpr std::array<char, 4> m_availableOperators{'*', '/', '+', '-'};
    static constexpr int min_operands_number{2};
};
