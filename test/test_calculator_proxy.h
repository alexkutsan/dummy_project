#pragma once
#include "project.h"

namespace dev {

class TestCalculatorProxy {
public:
    explicit TestCalculatorProxy (const Project & calculator) {
        calc = calculator;
    }

    std::vector<double> process(const std::string &input)
    {
      return calc.process(input);
    }

    bool isOperator(const std::string & arg) const {
      return calc.isOperator(arg);
    }
    void applyOperation(const std::string & operation,
                      std::vector<double> &operands) const
    {
      return calc.applyOperation(operation, operands);
    }
    std::vector<std::string> parceInput(const std::string &input)
    {
      return calc.parceInput(input);
    }

    std::vector<double> processArguments(const std::vector<std::string> &args)
    {
      return calc.processArguments(args);
    }

private:
  Project calc;
};

}  // namespace dev
