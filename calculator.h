#pragma once

#include "icalculator.h"

namespace dev {

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(const std::string& expression);

private:
    bool isOperator(const std::string& token);
    double evalOperation(const double& operand1, const double& operand2, const std::string& operatr);
};

}  // namespace dev
