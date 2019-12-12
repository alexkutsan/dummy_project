#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "ICalculator.h"

#include <vector>
#include <string>
#include <limits>
#include <memory>

namespace dev {

  class Calculator : public ICalculator {
    public:
      Calculator(std::unique_ptr<std::vector<int>> numbers, 
                 std::unique_ptr<std::vector<std::string>> operators);
      int calculate() override;

    private:
      int add(int first, int second);
      int div(int first, int second);
      int dec(int first, int second);
      int mul(int first, int second);
      
      std::unique_ptr<std::vector<int>> numbers_;
      std::unique_ptr<std::vector<std::string>> operators_;
  };
}

#endif
