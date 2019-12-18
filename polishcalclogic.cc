#include "polishcalclogic.h"
#include <assert.h>
#include <iostream>

namespace PolishCalcComponent {

void PolishCalcLogic::addValue(const value_t &val)
{
    m_values.push(val);
}

void PolishCalcLogic::process(operation_t operation)
{
    assert(m_values.size() >= 2);

    auto b = m_values.top();
    m_values.pop();

    auto a = m_values.top();
    m_values.pop();

    m_values.push(operation(a, b));
}

value_t PolishCalcLogic::getResult() const
{
    assert(m_values.size() == 1);

    return m_values.top();
}

void PolishCalcLogic::reset()
{
    m_values = std::stack<value_t>();
}

}
