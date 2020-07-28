#include "calculator.h"
#include "calculator_exception.h"

#include <iterator>
#include <sstream>

namespace dev {

bool Calculator::isValidExpression(const std::vector<std::string>& tokens) {
    int noOfOperands = 0;
    for (auto token : tokens) {
        if ((noOfOperands < 2) && (!Operand::isOperand(token))) {
            throw InvalidOperandException();
        }
        if (Operand::isOperand(token)) {
            noOfOperands++;
        } else {
            noOfOperands--;
        }
    }
    return (noOfOperands == 1);
}

void Calculator::parseTokens(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
    if (!isValidExpression(tokens)) {
        throw InvalidExpressionException();
    }
    for (auto token : tokens) {
        if (Operand::isOperand(token)) {
            operandsList_.push_back(Operand(token));
        } else {
            operatorsList_.push_back(OperatorFactory::getOperator(token));
        }
    }
}

double Calculator::calc(const std::string& expression) {
    parseTokens(expression);
    for (const auto& operatr : operatorsList_) {
        const Operand operand1 = operandsList_.front();
        operandsList_.pop_front();
        const Operand operand2 = operandsList_.front();
        operandsList_.pop_front();

        const double res = operatr->calculate(operand1, operand2);
        operandsList_.push_front(Operand(res));
    }

    return operandsList_.front().value();
}

}  // namespace dev
