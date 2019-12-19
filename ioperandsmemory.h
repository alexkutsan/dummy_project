#ifndef IOPERANDSMEMORY
#define IOPERANDSMEMORY

#include "polishcalctypes.h"

namespace PolishCalcComponent {

class IOperandsMemory{
public:
    virtual value_t getOperand() = 0;
    virtual void putOperand(const value_t&) = 0;
    virtual void applyOperation(operation_t) = 0;
    virtual unsigned int size() = 0;

    virtual ~IOperandsMemory() = default;
};

}

#endif // IOPERANDSMEMORY

