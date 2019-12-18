#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "ICalculator.h"
#include "CustomStack.h"

#include <vector>
#include <string>
#include <limits>
#include <memory>

namespace dev {

  using namespace types;

  class Calculator : public ICalculator {
    public:
      Calculator(NumbersStackPtr numbers, OperatorsListPtr operators);
      float calculate() override;

    private:
      float add(float first, float second);
      float div(float first, float second);
      float dec(float first, float second);
      float mul(float first, float second);
      
      NumbersStackPtr numbers_;
      OperatorsListPtr operators_;
  };
}

#endif
