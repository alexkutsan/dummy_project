#pragma once

#include "icalculator.h"

#include <vector>

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
    bool isValid();
    double calculate(const Operand& operand1, const Operand& operand2);
private:
    char sign_;
};

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(const std::string& expression);
private:
    std::vector<std::string> parseTokens(const std::string& expression) const;
};

}  // namespace dev
