#ifndef CALCOPERATIONS_H
#define CALCOPERATIONS_H

#include <string>
#include <vector>
#include "polishcalctypes.h"
#include "ioperandsmemory.h"

namespace PolishCalcComponent {

    void split2Tokens(const std::string& in, std::vector<std::string>& out);

    IOperandsMemory* makeMemory();
}

#endif // CALCOPERATIONS_H
