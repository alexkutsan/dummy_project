#include "calculator.h"
#include "calculator_exception.h"

#include <array>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stack>

namespace dev {

IToken::IToken(const std::string& token):token_(token) {}

Operand::Operand(const std::string& token):IToken(token) {
    try {
        value_ = std::stod(token);
    } catch (const std::invalid_argument&) {
        throw InvalidOperandException();
    } catch (const std::out_of_range&) {
        throw OperandOutOfRangeException();
    }
}

double Operand::value() const {
    return value_;
}

Operator::Operator(const std::string& token):IToken(token) {
    // ToDo validate operator and raise exception
    sign_ = token[0];
}

bool Operator::isValid() {
    std::array<char, 4> operators = {'+', '-', '*', '/'};
    return (std::find(operators.begin(), operators.end(), sign_) != operators.end());
}

double Operator::calculate(const Operand& operand1, const Operand& operand2) {
    switch (sign_)
    {
    case '+':
        return (operand2.value() + operand1.value());
    case '-':
        return (operand2.value() - operand1.value());
    case '*':
        return (operand2.value() * operand1.value());
    case '/':
        if (operand1.value() == 0) {
            throw DivideByZeroException();
        }
        return (operand2.value() / operand1.value());
    default:
        throw InvalidOperatorException();
    }
}

std::vector<std::string> Calculator::parseTokens(const std::string& expression) const {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
    return tokens;  
}

double Calculator::calc(const std::string& expression) {
    std::vector<std::string> tokens = parseTokens(expression);
    std::stack<std::string> stkTokens;
    for (auto token : tokens) {
        Operator operatr = Operator(token);
        if (operatr.isValid()) {
            Operand operand1 = Operand(stkTokens.top());
            stkTokens.pop();
            Operand operand2 = Operand(stkTokens.top());
            stkTokens.pop();

            stkTokens.push(std::to_string(operatr.calculate(operand1, operand2)));
        } else {
            stkTokens.push(token);
        }
    }

    return std::stod(stkTokens.top());
}

}  // namespace dev
