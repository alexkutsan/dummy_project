#include "calculator.h"

namespace dev {

bool Calculator::isOperator(char op){
    switch (op){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

void Calculator::getVariables(float& firstOperand, float& secondOperand)
{
    firstOperand = mOperandStack.top();
    mOperandStack.pop();
    secondOperand = mOperandStack.top();
    mOperandStack.pop();
}

double Calculator::evaluate(const std::string& expression)
{
    double ret =0.0;
    float firstOperand,secondOperand;
    firstOperand=secondOperand=0.0;
    for(int index=0;index < expression.length();index++)
    {
        // ignore the spaces
        if (isspace(expression[index])){
            continue;
        }

        // Push to stack, if digit
        if(isdigit(expression[index]))
        {
            std::string digitsStr;

            while (index < expression.size() && ((isdigit(expression[index]) || expression[index] == '.')))
            {
                digitsStr.push_back(expression[index]);
                index++;
            }

            mOperandStack.push(stof(digitsStr));
            // Decrease index as currently points to advanced element
            index--;
        }
        // Check if operator and perform the operation of numbers from stack
        else if (isOperator(expression[index])){
            getVariables(firstOperand,secondOperand);
            if (expression[index] == '+'){
                ret = firstOperand+secondOperand;
            }
            if (expression[index] == '-'){
                ret = secondOperand-firstOperand;
            }
            if (expression[index] == '*'){
                ret = firstOperand*secondOperand;
            }
            if (expression[index] == '/'){
                ret = secondOperand/firstOperand;
            }

            // push the final result
            mOperandStack.push(ret);
        }
        }
    // return answer
    return mOperandStack.top();
}

}  // namespace dev