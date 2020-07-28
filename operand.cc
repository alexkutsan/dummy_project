#include "operand.h"
#include "calculator_exception.h"

#include <sstream>
#include <string>

namespace dev {

bool Operand::isOperand(const std::string& token) {
    // Check if the first character of token is digit.
    return ((token[0] >= 48) && (token[0] <= 57));
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
