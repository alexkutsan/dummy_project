#include "operandsmemory.h"

PolishCalcComponent::value_t PolishCalcComponent::OperandsMemory::getOperand()
{
    value_t res = m_memory.top();
    m_memory.pop();

    return res;
}

void PolishCalcComponent::OperandsMemory::putOperand(const PolishCalcComponent::value_t& val)
{
    m_memory.push(val);
}

void PolishCalcComponent::OperandsMemory::applyOperation(PolishCalcComponent::operation_t operation)
{
    operation(this);
}

unsigned int PolishCalcComponent::OperandsMemory::size()
{
    return m_memory.size();
}
