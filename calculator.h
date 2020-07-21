#include "icalculator.h"

namespace dev {

class Calculator : public ICalculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    double calc(std::string expression);

private:
    bool isOperator(const std::string& token);
    double evalOperation(double operand1, double operand2, std::string operatr);
};

}  // namespace dev
