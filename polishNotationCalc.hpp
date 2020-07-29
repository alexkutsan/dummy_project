#pragma once
#include <iostream>
#include <stack>
#include <utility>
#include <functional>
#include <string>
#include <iterator>
#include <map>

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
    using functionCall = std::function<double(double, double)>;
    class PolishCalc
    {
    public:
        double calc(const std::string &);
        PolishCalc();

    private:
        bool isNumeric(const char num);
        bool isOperator(const char num);
        void insertFunctionInsideMap();
        void pushOperandInStack(const std::string &str, int& curr_pos);
        std::pair<double, double> getOperandFromStack();
        std::stack<double> mCalculatorStack;
        std::map<const char, functionCall> mOperatorMap;
    };

} // namespace dev
