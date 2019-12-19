#pragma once

#include <queue>
#include <string>
#include "polishcalc.h"

namespace dev {


class Project {

public:
  PolishCalcComponent::value_t run(const std::string& str);

private:
  PolishCalcComponent::PolishCalc m_calc;
};
}  // namespace dev
