#pragma once

namespace dev
{
    class IOperator
    {
    public:
        virtual double operator()(double value1, double value2) = 0;
        virtual bool isValid() const
        {
            return true;
        }
    };
}
