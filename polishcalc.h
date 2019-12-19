#ifndef POLISHCALC_H
#define POLISHCALC_H

#include <vector>
#include <string>
#include "ioperandsmemory.h"

namespace PolishCalcComponent {


class PolishCalc
{

public:
    value_t calculate(const std::string& inputStr);


private:
    void processTokens(const std::vector<std::string>& tokens, IOperandsMemory* memory);

};

} //PolishCalc

#endif // POLISHCALC_H
