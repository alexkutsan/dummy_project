#pragma once
#include <iostream>
#include <stack>

namespace dev
{
    /*!
 * \brief Exception class for Calculator.
 */
    class Exception final : public std::exception
    {
    public:
        template <typename T>
        Exception(T &&msg)
            : mMsg(std::forward<T>(msg))
        {
        }

        const char *what() const noexcept override
        {
            return mMsg.c_str();
        }

    private:
        const std::string mMsg;
    };

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
