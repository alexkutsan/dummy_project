#include "polishNotationCalc.hpp"
namespace dev
{
    double PolishCalc::performOperation(char operation, double firstOperand, double secOperand)
    {
        double res{};
        switch (operation)
        {
        case '+':
            res = firstOperand + secOperand;
            break;

        case '-':
            res = firstOperand - secOperand;
            break;

        case '*':
            res = firstOperand * secOperand;
            break;

        case '/':
            if (secOperand == 0)
                throw std::runtime_error("divide by zero");
            res = firstOperand / secOperand;
            break;
        default:
            throw std::runtime_error("not a valid operation to perform");
            break;
        }
        return res;
    }
    bool PolishCalc::isNumeric(char num)
    {
        double temp = num - '0';
        if (temp >= 0 && temp <= 9)
            return true;

        return false;
    }
    bool PolishCalc::isOperator(char num)
    {
        if (num == '+' || num == '-' || num == '*' || num == '/')
            return true;
        return false;
    }
    double PolishCalc::calc(std::string str)
    {
        if (str.size() == 0)
            return 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                continue;
            if (isNumeric(str[i]))
            {
                double operand = 0;
                std::string temp = "";
                while (i < str.size() && !(str[i] == ' '))
                {

                    temp = temp + str[i];
                    i++;
                }
                operand = atof(temp.c_str());

                mStack.push(operand);
                i--;
            }
            if (isOperator(str[i]))
            {
                double secOperand = 0;
                double firstOperand = 0;

                if (mStack.size() >= 2)
                {
                    secOperand = mStack.top();
                    mStack.pop();
                    firstOperand = mStack.top();
                    mStack.pop();
                }
                else
                {
                    throw std::runtime_error("No operand to work on");
                }
                
                double res=0;
                //try
                {
                    res = performOperation(str[i], firstOperand, secOperand);
                    mStack.push(res);
                }
                // catch (const std::exception &e)
                // {
                //     std::cout << "calc::Exception" << e.what();
                // }
            }
        }

        if (mStack.size() > 1)
            throw std::runtime_error("Not a valid string");

        return mStack.top();
    }
} // namespace dev