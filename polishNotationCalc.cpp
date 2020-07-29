#include "polishNotationCalc.hpp"
namespace dev
{
    PolishCalc::PolishCalc()
    {
        insertFunctionInsideMap();
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
   
    double PolishCalc::calc( const std::string &str)
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
                res = mOperatorMap[str[i]](operandVal.first, operandVal.second);
                mCalculatorStack.push(res);
            }
        }

        if (mCalculatorStack.size() > 1)
            throw Exception{"Not a valid string"};

        return mCalculatorStack.top();
    }

    void PolishCalc::pushOperandInStack(const std::string &str, int& curr_pos)
    {
        double operand = 0;
        std::string temp = "";
        while (curr_pos < str.size() && !(str[curr_pos] == ' '))
        {
            temp = temp + str[curr_pos];
            curr_pos++;
        }
        operand = atof(temp.c_str());
        mCalculatorStack.push(operand);
        curr_pos--;
       
    }
    std::pair<double, double> PolishCalc::getOperandFromStack()
    {
        double secOperand = 0;
        double firstOperand = 0;
        if (mCalculatorStack.size() < 2)
        {
            throw Exception{"No operand to work on"};
        }
        secOperand = mCalculatorStack.top();
        mCalculatorStack.pop();
        firstOperand = mCalculatorStack.top();
        mCalculatorStack.pop();
        return std::make_pair(firstOperand, secOperand);
    }
    void PolishCalc::insertFunctionInsideMap()
    {
        mOperatorMap.insert(std::make_pair('+', [](const double a, const double b) { return a + b; }));
        mOperatorMap.insert(std::make_pair('-', [](const double a, const double b) { return a - b; }));
        mOperatorMap.insert(std::make_pair('*', [](const double a, const double b) { return a * b; }));
        mOperatorMap.insert(std::make_pair('/', [](const double a, const double b) { 
            if(b==0)
            {
                throw Exception{"divide by zero"};
            }
            return a / b; }));
    }
} // namespace dev