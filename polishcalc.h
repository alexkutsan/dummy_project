#ifndef POLISHCALC_H
#define POLISHCALC_H

#include <vector>
#include <string>
#include "polishcalclogic.h"

namespace PolishCalcComponent {

enum class CalcError{
    NO_ERROR,
    PARSE_ERROR,
    PROCESS_ERROR,
    LOGIC_ERROR
};

class PolishCalc
{

public:

    CalcError process(const std::string& str, value_t& res);

private:
    CalcError processOperations(const std::vector<std::string>& operations);
    operation_t* getOperation(const std::string& opStr);


    PolishCalcLogic m_logic;

};

} //PolishCalc

#endif // POLISHCALC_H
