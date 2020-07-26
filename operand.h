#pragma once

#include "token.h"

namespace dev {

class Operand : public Token {
public:
    Operand(const std::string& token);
    double value() const;
private:
    double value_;
};

}  // namespace dev
