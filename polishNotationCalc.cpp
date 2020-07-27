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
                throw Exception{"divide by zero"};
            res = firstOperand / secOperand;
            break;
        default:
            throw Exception{"not a valid operation to perform"};
            break;
        }
        return res;
    }
    bool PolishCalc::isNumeric(const char num)
    {
        double temp = num - '0';
        if (temp >= 0 && temp <= 9)
            return true;

        return false;
    }
    bool PolishCalc::isOperator(const char num)
    {
        if (num == '+' || num == '-' || num == '*' || num == '/')
            return true;
        return false;
    }
    double PolishCalc::calc(const std::string &str)
    {
        if (str.size() == 0)
            throw Exception{"Nothing to work on as Input is empty"};
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                continue;
            if (isNumeric(str[i]))
            {
                pushOperandInStack(str, i);
            }
            if (isOperator(str[i]))
            {
                auto operandVal = getOperandFromStack();
                double res = 0;
                res = performOperation(str[i], operandVal.first, operandVal.second);
                mStack.push(res);
            }
        }

        if (mStack.size() > 1)
            throw Exception{"Not a valid string"};

        return mStack.top();
    }

    void PolishCalc::pushOperandInStack(const std::string &str, int &curr_pos)
    {
        double operand = 0;
        std::string temp = "";
        while (curr_pos < str.size() && !(str[curr_pos] == ' '))
        {
            temp = temp + str[curr_pos];
            curr_pos++;
        }
        operand = atof(temp.c_str());
        mStack.push(operand);
        curr_pos--;
    }
    std::pair<double, double> PolishCalc::getOperandFromStack()
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
            throw Exception{"No operand to work on"};
        }

        return std::make_pair(firstOperand, secOperand);
    }
} // namespace dev