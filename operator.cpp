#include "operator.h"
#include <stdexcept>

namespace dev
{
    double OperatorAdd::operator()(double value1, double value2)
    {
        return value1 + value2;
    }

    double OperatorSub::operator()(double value1, double value2)
    {
        return value1 - value2;
    }

    double OperatorMul::operator()(double value1, double value2)
    {
        return value1 * value2;
    }

    double OperatorDiv::operator()(double value1, double value2)
    {
        if (value2 == 0) {
            throw std::logic_error("Division by zero");
        }
        return value1 / value2;
    }

    double NotOperator::operator()(double, double)
    {
        return 0;
    }

    bool NotOperator::isValid() const
    {
        return false;
    }
}
