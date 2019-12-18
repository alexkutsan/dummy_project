#ifndef CALCOPERATIONS_H
#define CALCOPERATIONS_H

#include <string>
#include "polishcalctypes.h"

namespace PolishCalcComponent {

    void split2Tokens(const std::string& in, std::vector<std::string>& out);

    operation_t* getOperation(const std::string& opStr);

    value_t getValue(const std::string& valStr);

}

#endif // CALCOPERATIONS_H
