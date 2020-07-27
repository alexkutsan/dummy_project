#include "operand.h"
#include "calculator_exception.h"

#include <sstream>

namespace dev {

Operand::Operand(const std::string& token) {
    try {
        value_ = std::stod(token);
    } catch (const std::invalid_argument&) {
        throw InvalidOperandException();
    } catch (const std::out_of_range&) {
        throw OperandOutOfRangeException();
    }
}

double Operand::value() const {
    return value_;
}

}  // namespace dev
