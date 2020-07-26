#pragma once

#include "icalculator.h"

#include <vector>

namespace dev {

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(const std::string& expression);
private:
    std::vector<std::string> parseTokens(const std::string& expression) const;
};

}  // namespace dev
