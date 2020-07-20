#pragma once
#include <iostream>
#include <stack>

namespace dev
{
    class PolishCalc
    {
        public:
        double calc(std::string);
       

        private:
            bool isNumeric(char num);
            bool isOperator(char num);
            double performOperation(char operation, double firstOperand, double secOperand);
            std::stack<double> mStack;
        
    };

} // namespace dev
