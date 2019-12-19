#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Stack.h"

class Calculator
{
public:
    Calculator(Stack &stk);
    double exe();///TODO rename execute

private:
    Stack stk_;
};

#endif // CALCULATOR_H
