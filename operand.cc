#include "operand.h"
#include "calculator_exception.h"

#include <sstream>
#include <string>

namespace dev {

bool Operand::isOperand(const std::string& token) {
    auto is_sign = [&token] (const int& index) -> bool {
        return ((token[index] == 43) || (token[index] == 45));
    };
    auto is_digit = [&token] (const int& index) -> bool {
        return ((token[index] >= 48) && (token[index] <= 57));
    };
    int index = 0;
    if (is_sign(index)) {
        index = 1;
    }
    return is_digit(index);
}

Operand::Operand(const std::string& token) {
    try {
        value_ = std::stod(token);
    } catch (const std::invalid_argument&) {
        throw InvalidOperandException();
    } catch (const std::out_of_range&) {
        throw OperandOutOfRangeException();
    }
}

Operand::Operand(const double& value):value_(value) {}

double Operand::value() const {
    return value_;
}

}  // namespace dev
