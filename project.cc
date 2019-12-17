#include "project.h"

namespace dev {

PolishCalcComponent::value_t Project::run(const std::string &str) {
    PolishCalcComponent::value_t res;

    m_calc.process(str, res);

    return res;
}

}  // namespace dev
