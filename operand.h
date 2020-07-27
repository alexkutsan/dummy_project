#pragma once

#include <string>

namespace dev {

class Operand {
public:
    Operand(const std::string& token);
    double value() const;
private:
    double value_;
};

}  // namespace dev
