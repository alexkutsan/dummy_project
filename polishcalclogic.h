#ifndef POLISHCALCLOGIC_H
#define POLISHCALCLOGIC_H

#include <stack>
#include "polishcalctypes.h"

namespace PolishCalcComponent {

class PolishCalcLogic
{
public:
    void reset();
    void addValue(const value_t& val);
    void process(operation_t operation);

    value_t getResult() const;

private:
    std::stack<value_t> m_values;
};

} //PolishCalc

#endif // POLISHCALCLOGIC_H
