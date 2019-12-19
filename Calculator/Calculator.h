#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "ICalculator.h"
#include "CustomStack.h"
#include "utils.h"

#include <vector>
#include <string>
#include <limits>
#include <memory>

namespace dev {

  class Calculator : public ICalculator {
    public:
      Calculator(types::NumbersStackPtr numbers, types::OperatorsListPtr operators);
      float calculate() override;

    private:
      float add(float first, float second);
      float div(float first, float second);
      float dec(float first, float second);
      float mul(float first, float second);
      
      types::NumbersStackPtr numbers_;
      types::OperatorsListPtr operators_;
  };
}

#endif
