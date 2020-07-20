#include "calculator.h"


#include <array>
#include <algorithm>
#include <exception>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>

namespace dev {

double Calculator::calc(std::string expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());

    std::stack<std::string> stkTokens;

    std::array<std::string, 4> operators = {"+", "-", "*", "/"};
    for (auto token : tokens) {
        if (std::find(operators.begin(), operators.end(), token) != operators.end()) {
            double operand1 = std::stod(stkTokens.top());
            stkTokens.pop();
            double operand2 = std::stod(stkTokens.top());
            stkTokens.pop();

            stkTokens.push(std::to_string(evalOperation(operand1, operand2, token)));
        } else {
            stkTokens.push(token);
        }
    }

    return std::stod(stkTokens.top());
}

double Calculator::evalOperation(double operand1, double operand2, std::string operatr) {
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
            // Divide by zero exception
            throw std::exception();
        }
        return (operand2 / operand1);
    default:
        // Invalid operator exception
        throw std::exception();
    }
}

}  // namespace dev
