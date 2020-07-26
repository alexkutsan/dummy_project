#pragma once

#include <string>

namespace dev {

class Token {
public:
    Token();
    static bool isOperator(const std::string& token);
};

}  // namespace dev
