#include "icalculator.h"

namespace dev {

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(std::string expression);
};

}  // namespace dev
