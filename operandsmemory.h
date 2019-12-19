#ifndef OPERANDSMEMORY_H
#define OPERANDSMEMORY_H

#include <stack>
#include "ioperandsmemory.h"
#include "polishcalctypes.h"

namespace PolishCalcComponent {

class OperandsMemory: public IOperandsMemory{
public:
    virtual value_t getOperand() override;
    virtual void putOperand(const value_t&) override;
    virtual void applyOperation(operation_t operation) override;
    virtual unsigned int size() override;


private:
    std::stack<value_t> m_memory;
};

}

#endif // OPERANDSMEMORY_H
