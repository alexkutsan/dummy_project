#include "operator.h"
#include "calculator_exception.h"

#include <array>
#include <algorithm>

namespace dev {

Operator::Operator(Calculate calculate):calculate(calculate) {}

OperatorMap OperatorFactory::operators_ = {
    {
        '+', [] (const Operand& operand1, const Operand& operand2) -> double { return operand1.value() + operand2.value();}
    },
    {
        '-', [] (const Operand& operand1, const Operand& operand2) -> double { return operand1.value() - operand2.value();}
    },
    {
        '*', [] (const Operand& operand1, const Operand& operand2) -> double { return operand1.value() * operand2.value();}
    },
    {
        '/', [] (const Operand& operand1, const Operand& operand2) -> double {
                if (operand2.value() == 0) {
                    throw DivideByZeroException();
                }
                return operand1.value() / operand2.value();
             }
    }
};

std::unique_ptr<Operator> OperatorFactory::getOperator(const std::string& token) {
    auto fn = operators_[token[0]];
    if (fn == nullptr) {
        throw InvalidOperatorException();
    }
    return std::make_unique<Operator>(fn);
}

}  // namespace dev
