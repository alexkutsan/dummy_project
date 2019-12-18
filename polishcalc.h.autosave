#ifndef POLISHCALC_H
#define POLISHCALC_H

#include <vector>
#include <string>
#include "polishcalclogic.h"

namespace PolishCalcComponent {


class PolishCalc
{

public:
    value_t calculate(const std::string& inputStr);

private:    
    void processTokens(const std::vector<std::string>& tokens);
    void processToken(const std::string& token);

    PolishCalcLogic m_logic;
};

} //PolishCalc

#endif // POLISHCALC_H
