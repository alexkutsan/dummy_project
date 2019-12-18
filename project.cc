#include "project.h"

namespace dev {

PolishCalcComponent::value_t Project::run(const std::string &str) {
    return m_calc.calculate(str);
}

}  // namespace dev
