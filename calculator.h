#pragma once

#include "icalculator.h"

namespace dev {

class IToken {
public:
    IToken(const std::string& token);
private:
    const std::string& token_;
};

class Operand : public IToken {
public:
    Operand(const std::string& token);
    double value() const;
private:
    double value_;
};

class Operator : public IToken {
public:
    Operator(const std::string& token);
    char value() const;
private:
    char value_;
};

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(const std::string& expression);

private:
    bool isOperator(const std::string& token);
    double evalOperation(const Operand& operand1, const Operand& operand2, const Operator& operatr);
};

}  // namespace dev
