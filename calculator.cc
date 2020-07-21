#include "calculator.h"
#include "calculator_exception.h"

#include <array>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>

namespace dev {

bool Calculator::isOperator(const std::string& token) {
    std::array<std::string, 4> operators = {"+", "-", "*", "/"};
    return (std::find(operators.begin(), operators.end(), token) != operators.end());
}

double Calculator::toOperand(const std::string& token) {
    try {
        return std::stod(token);
    } catch (const std::invalid_argument&) {
        throw InvalidOperandException();
    } catch (const std::out_of_range&) {
        throw OperandOutOfRangeException();
    }
}

double Calculator::calc(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    std::stack<std::string> stkTokens;
    for (auto token : tokens) {
        if (isOperator(token)) {
            double operand1 = toOperand(stkTokens.top());
            stkTokens.pop();
            double operand2 = toOperand(stkTokens.top());
            stkTokens.pop();

            stkTokens.push(std::to_string(evalOperation(operand1, operand2, token)));
        } else {
            stkTokens.push(token);
        }
    }

    return std::stod(stkTokens.top());
}

double Calculator::evalOperation(const double& operand1, const double& operand2, const std::string& operatr) {
    char op = operatr[0];
    switch (op)
    {
    case '+':
        return (operand2 + operand1);
    case '-':
        return (operand2 - operand1);
    case '*':
        return (operand2 * operand1);
    case '/':
        if (operand1 == 0) {
            throw DivideByZeroException();
        }
        return (operand2 / operand1);
    default:
        throw InvalidOperatorException();
    }
}

}  // namespace dev
