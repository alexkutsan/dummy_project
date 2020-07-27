#pragma once

#include "ioperatorfactory.h"

namespace dev
{
    class OperatorFactory : public IOperatorFactory
    {
    public:
        IOperator *makeOperator(std::string oper);
    };
}
