#ifndef POLISHCALCTYPES
#define POLISHCALCTYPES

#include <functional>

namespace PolishCalcComponent {

using value_t = double;

class IOperandsMemory;
using operation_t = std::function<void(PolishCalcComponent::IOperandsMemory*)>;

}

#endif // POLISHCALCTYPES

