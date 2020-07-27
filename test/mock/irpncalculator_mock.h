#include "irpncalculator.h"
#include <gmock/gmock.h>

namespace dev
{

    class MockIRPNCalculator : public IRPNCalculator
    {
    public:
        MOCK_METHOD0(run, double());
    };

}// namespace dev
