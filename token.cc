#include "token.h"

#include <array>
#include <algorithm>

namespace dev {

Token::Token() {}

bool Token::isOperator(const std::string& token) {
    std::array<std::string, 4> operators = {"+", "-", "*", "/"};
    return (std::find(operators.begin(), operators.end(), token) != operators.end());
}

}  // namespace dev
