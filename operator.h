#pragma once

#include "ioperator.h"

namespace dev
{
    class OperatorAdd : public IOperator
    {
        // Operator interface
    public:
        double operator()(double value1, double value2) override;
    };

    class OperatorSub : public IOperator
    {
        // Operator interface
    public:
        double operator()(double value1, double value2) override;
    };

    class OperatorMul : public IOperator
    {
        // Operator interface
    public:
        double operator()(double value1, double value2) override;
    };

    class OperatorDiv : public IOperator
    {
        // Operator interface
    public:
        double operator()(double value1, double value2) override;
    };

    class NotOperator : public IOperator
    {
        // Operator interface
    public:
        double operator()(double, double) override;
        bool isValid() const override;
    };
}
