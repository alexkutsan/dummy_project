#include "rpncalculator.h"
#include "operatorfactory.h"
#include <iostream>
#include <stdexcept>

namespace dev
{
    void RPNCalculator::addExpression(std::string expr)
    {
        m_expression = expr;
    }

    double RPNCalculator::run()
    {
        std::string::size_type startPos = 0;
        std::string nextExpr;
        while (startPos < m_expression.size()) {
            std::string::size_type pos = m_expression.find(' ', startPos);
            nextExpr = m_expression.substr(startPos, (pos != std::string::npos) ? pos - startPos : m_expression.size());
            push(isOperator(nextExpr) ? evaluate(pop(), pop()) : newNumber(nextExpr));
            printStack();
            if (pos == std::string::npos) {
                return pop();
            }
            startPos = pos + 1;
        }
        return 0;
    }

    bool RPNCalculator::isOperator(const std::string &expr)
    {
        OperatorFactory factory;
        m_operator.reset(factory.makeOperator(expr));
        return m_operator->isValid();
    }

    double RPNCalculator::evaluate(double value1, double value2) const
    {
        return (*m_operator)(value1, value2);
    }

    double RPNCalculator::newNumber(const std::string &str) const
    {
        return stod(str);
    }

    double RPNCalculator::pop()
    {
        if (m_cur_pos < 0) {
            throw std::underflow_error("stack is empty");
        }
        return m_stack[m_cur_pos--];
    }

    void RPNCalculator::push(double value)
    {
        if (m_cur_pos + 1 >= MAX_SIZE) {
            throw std::overflow_error("stack is full");
        }
        m_stack[++m_cur_pos] = value;
    }

    void RPNCalculator::printStack() const
    {
        std::cout << "stack: ";
        for (int i = 0; i <= m_cur_pos; ++i) {
            std::cout << m_stack[i] << " ";
        }
        std::cout << std::endl;
    }
}// namespace dev
