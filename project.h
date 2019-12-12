#pragma once

#include "iproject.h"

namespace dev {

// TODO: Rename Project
class Project : public IProject {
friend class TestCalculatorProxy;
public:
  std::vector<double> process(const std::string &input) override;
// TODO: make private and create object for testing private methods
// private:
  bool isOperator(const std::string & arg) const;
  void applyOperation(const std::string & operation,
                      std::vector<double> &operands) const;
  std::vector<std::string> parceInput(const std::string &input);
  std::vector<double> processArguments(const std::vector<std::string> &args);
};

}  // namespace dev
