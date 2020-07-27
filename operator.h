#pragma once

#include "operand.h"

#include <memory>

namespace dev {

class Operator {
public:
    virtual double calculate(const Operand& operand1, const Operand& operand2) const = 0;
};

class AddOperator : public Operator {
public:
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class SubtractOperator : public Operator {
public:
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class MultiplyOperator : public Operator {
public:
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class DivideOperator : public Operator {
public:
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class OperatorFactory {
public:
    static std::unique_ptr<Operator> getOperator(const std::string& token);
};

}  // namespace dev
