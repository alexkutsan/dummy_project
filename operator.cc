#include "operator.h"
#include "calculator_exception.h"

#include <array>
#include <algorithm>

namespace dev {

Operator::Operator() {}

bool Operator::isOperator(const std::string& token) {
    std::array<std::string, 4> operators = {"+", "-", "*", "/"};
    return (std::find(operators.begin(), operators.end(), token) != operators.end());
}

AddOperator::AddOperator():Operator() {}

double AddOperator::calculate(const Operand& operand1, const Operand& operand2) const {
    return operand2.value() + operand1.value();
}

SubtractOperator::SubtractOperator():Operator() {}

double SubtractOperator::calculate(const Operand& operand1, const Operand& operand2) const {
    return operand2.value() - operand1.value();
}

MultiplyOperator::MultiplyOperator():Operator() {}

double MultiplyOperator::calculate(const Operand& operand1, const Operand& operand2) const {
    return operand2.value() * operand1.value();
}

DivideOperator::DivideOperator():Operator() {}

double DivideOperator::calculate(const Operand& operand1, const Operand& operand2) const {
    if (operand1.value() == 0) {
        throw DivideByZeroException();
    }
    return operand2.value() / operand1.value();
}


std::unique_ptr<Operator> OperatorFactory::getOperator(const std::string& token) {
    switch (token[0])
    {
    case '+':
        return std::make_unique<AddOperator>();
    case '-':
        return std::make_unique<SubtractOperator>();
    case '*':
        return std::make_unique<MultiplyOperator>();
    case '/':
        return std::make_unique<DivideOperator>();
    }
}

}  // namespace dev
