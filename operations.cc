#include <assert.h>
#include "operations.h"
#include "ioperandsmemory.h"

namespace PolishCalcComponent {

value_t add(IOperandsMemory* memory){
    auto b = memory->getOperand();
    auto a = memory->getOperand();

    memory->putOperand(a + b);
}

value_t sub(IOperandsMemory* memory){
    auto b = memory->getOperand();
    auto a = memory->getOperand();

    memory->putOperand(a - b);
}

value_t div(IOperandsMemory* memory){
    auto b = memory->getOperand();
    auto a = memory->getOperand();

    memory->putOperand(a / b);
}

value_t mul(IOperandsMemory* memory){
    auto b = memory->getOperand();
    auto a = memory->getOperand();

    memory->putOperand(a * b);
}

value_t neg(IOperandsMemory* memory){
    auto a = memory->getOperand();

    memory->putOperand( -a );
}

enum class Operations: char{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    NEG = '!'
};

value_t getValue(const std::string &valStr)
{
    std::string::size_type sz;
    value_t value = std::stod(valStr, &sz);
    assert(sz == valStr.size());

    return value;
}

operation_t getPutOperation(const std::string &valStr)
{
    value_t value = getValue(valStr);

    operation_t result = [value](IOperandsMemory* memory){
        memory->putOperand(value);
    };

    return result;
}

operation_t getOperation(const std::string &opStr)
{
    if (opStr.length() == 1){

        switch (static_cast<Operations>(opStr[0])) {
        case Operations::ADD:
            return &add;
        case Operations::SUB:
            return &sub;
        case Operations::MUL:
            return &mul;
        case Operations::DIV:
            return &div;
        case Operations::NEG:
            return &neg;
        default:
            return getPutOperation(opStr);
        }
    }

    return getPutOperation(opStr);
}

}
