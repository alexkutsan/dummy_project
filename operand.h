#pragma once

#include <string>

namespace dev {

class Operand {
public:
    Operand(const std::string& token);
    double value() const;
    static bool isOperand(const std::string& token);
private:
    double value_;
};

}  // namespace dev
