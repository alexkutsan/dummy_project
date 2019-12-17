#ifndef POLISHCALCTYPES
#define POLISHCALCTYPES

#include <limits>
#include <queue>

namespace PolishCalcComponent {

using value_t = double;
constexpr value_t INVALID_VALUE = std::numeric_limits<value_t>::max();

using operation_t = value_t(const value_t&, const value_t&);

}

#endif // POLISHCALCTYPES

