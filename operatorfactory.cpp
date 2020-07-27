#include "operatorfactory.h"
#include "operator.h"

namespace dev
{
    IOperator *OperatorFactory::makeOperator(std::string oper)
    {
        if (oper.size() != 1) {
            return new NotOperator();
        }
        switch (oper[0]) {
        case '+':
            return new OperatorAdd();
        case '-':
            return new OperatorSub();
        case '*':
            return new OperatorMul();
        case '/':
            return new OperatorDiv();
        default:
            return new NotOperator();
        }
    }
}
