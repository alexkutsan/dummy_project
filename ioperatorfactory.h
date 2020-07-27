#pragma once

#include "ioperator.h"
#include "string"

namespace dev
{
    class IOperatorFactory
    {
    public:
        IOperator *makeOperator(std::string oper) const;
    };
}
