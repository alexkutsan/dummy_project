#pragma once

#include "operand.h"

#include <memory>

namespace dev {

class Operator {
public:
    Operator();
    virtual double calculate(const Operand& operand1, const Operand& operand2) const = 0;
    static bool isOperator(const std::string& token);
};

class AddOperator : public Operator {
public:
    AddOperator();
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class SubtractOperator : public Operator {
public:
    SubtractOperator();
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class MultiplyOperator : public Operator {
public:
    MultiplyOperator();
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class DivideOperator : public Operator {
public:
    DivideOperator();
    double calculate(const Operand& operand1, const Operand& operand2) const override;
};

class OperatorFactory {
public:
    static std::unique_ptr<Operator> getOperator(const std::string& token);
};

}  // namespace dev
