#include "calculator.h"
#include "calculator_exception.h"

#include <iterator>
#include <sstream>

namespace dev {

void Calculator::parseTokens(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
    for (auto token : tokens) {
        if (Operand::isOperand(token)) {
            operandsList_.push_back(Operand(token));
        } else {
            if (operandsList_.size() < 2) {
                throw InvalidOperandException();
            }
            operatorsList_.push_back(OperatorFactory::getOperator(token));
        }
    }
}

double Calculator::calc(const std::string& expression) {
    parseTokens(expression);
    for (const auto& operatr : operatorsList_) {
        if (operandsList_.size() < 2) {
            throw InvalidExpressionException();
        }
        Operand operand1 = operandsList_.front();
        operandsList_.pop_front();
        Operand operand2 = operandsList_.front();
        operandsList_.pop_front();

        operandsList_.push_front(Operand(std::to_string(operatr->calculate(operand1, operand2))));
    }

    if (operandsList_.size() != 1) {
        throw InvalidExpressionException();
    }

    return operandsList_.front().value();
}

}  // namespace dev
