#pragma once

#include "icalculator.h"

#include "operand.h"
#include "operator.h"

#include <vector>

namespace dev {

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(const std::string& expression);
private:
    std::vector<std::string> parseTokens(const std::string& expression);
    bool isValidExpression(const std::vector<std::string>& tokens);
};

}  // namespace dev
