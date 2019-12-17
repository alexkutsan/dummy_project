#include "polishcalclogic.h"

namespace PolishCalcComponent {

LogicError PolishCalcLogic::addValue(const value_t &val)
{
    m_values.push(val);

    return LogicError::NO_ERROR;
}

LogicError PolishCalcLogic::process(operation_t operation)
{
    if (m_values.size() < 2){
        return LogicError::NOT_ENOUTH_VALUES;
    }

    auto b = m_values.top();
    m_values.pop();

    auto a = m_values.top();
    m_values.pop();

    m_values.push(operation(a, b));

    return LogicError::NO_ERROR;
}

LogicError PolishCalcLogic::getResult(value_t &res)
{
    if (m_values.size() == 1){
        res = m_values.top();
        return LogicError::NO_ERROR;
    }
    else {
        return LogicError::RESULT_UNDEFINED;
    }
}

void PolishCalcLogic::reset()
{
    m_values = std::stack<value_t>();
}

}
