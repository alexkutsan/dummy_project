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
      int calculate() override;

    private:
      int add(int first, int second);
      int div(int first, int second);
      int dec(int first, int second);
      int mul(int first, int second);
      
      NumbersStackPtr numbers_;
      OperatorsListPtr operators_;
  };
}

#endif
