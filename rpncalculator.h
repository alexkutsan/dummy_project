#pragma once

#include "irpncalculator.h"
#include "ioperator.h"
#include <memory>

namespace dev
{
    class RPNCalculator : public IRPNCalculator
    {
        // IProject interface
    public:
        void addExpression(std::string expr);
        double run() override;

    private:
        double pop();
        void push(double value);
        bool isOperator(const std::string &oper);
        double evaluate(double value1, double value2) const;
        double newNumber(const std::string &value) const;
        void printStack() const;

    private:
        static constexpr int MAX_SIZE = 20;
        int m_cur_pos = -1;
        double m_stack[MAX_SIZE];
        std::string m_expression;
        std::unique_ptr< IOperator > m_operator;
    };

}// namespace dev
