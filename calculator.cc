#include "calculator.h"
#include "calculator_exception.h"

#include <iterator>
#include <sstream>
#include <stack>

namespace dev {

bool Calculator::isValidExpression(const std::vector<std::string>& tokens) {
    auto  is_operator = [] (const std::string& token) {
        return !Operand::isOperand(token);
    };

    auto check_operands_count_for_operator = [] (const int& noOfOperands) {
        if (noOfOperands < 2) {
            throw InvalidOperandException();
        }
    };

    int noOfOperands = 0;
    for (auto token : tokens) {
        if (is_operator(token)) {
            check_operands_count_for_operator(noOfOperands);
            noOfOperands--;
        } else {
            noOfOperands++;
        }
    }
    return (noOfOperands == 1);
}

std::vector<std::string> Calculator::parseTokens(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
    if (!isValidExpression(tokens)) {
        throw InvalidExpressionException();
    }
    return tokens;
}

double Calculator::calc(const std::string& expression) {
    const std::vector<std::string> tokens = parseTokens(expression);
    
    std::stack<Operand> tokensStack;
    for (auto token : tokens) {
        if (Operand::isOperand(token)) {
            tokensStack.push(Operand(token));
        } else {
            const Operand operand2 = tokensStack.top();
            tokensStack.pop();
            const Operand operand1 = tokensStack.top();
            tokensStack.pop();

            auto operatr = OperatorFactory::getOperator(token);
            const double res = operatr->calculate(operand1, operand2);
            tokensStack.push(Operand(res));
        }
    }

    return tokensStack.top().value();
}

}  // namespace dev
