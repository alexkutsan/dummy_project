#ifndef POLISHCALCLOGIC_H
#define POLISHCALCLOGIC_H

#include <stack>
#include "polishcalctypes.h"

namespace PolishCalcComponent {

enum class LogicError
{
    NO_ERROR,
    NOT_ENOUTH_VALUES,
    RESULT_UNDEFINED
};

class PolishCalcLogic
{
public:

    LogicError addValue(const value_t& val);
    LogicError process(operation_t operation);
    LogicError getResult(value_t& res);
    void reset();

private:

    std::stack<value_t> m_values;
};

} //PolishCalc

#endif // POLISHCALCLOGIC_H
