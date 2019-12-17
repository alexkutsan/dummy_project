#pragma once

#include "iproject.h"

namespace dev {

// TODO: Rename Project
class Project : public IProject {
friend class TestCalculatorProxy;
public:
/**
* @brief process applies math operations from args to operands from arfs
* @param args list of ordered arguments and operations
* @return calculation result
*/
  std::vector<double> process(const std::string &input) override;
private:
  /**
   * @brief isOperator check whether arg is operator
   * @param arg is being checked whether it is operator
   * @return whether arg is operator
   */
  bool isOperator(const std::string & arg) const;
  /**
   * @brief applyOperation
   * @param operation
   * @param operands
   */
  void applyOperation(const std::string & operation,
                      std::vector<double> &operands) const;
  /**
   * @brief parceInput
   * @param input
   * @return
   */
  std::vector<std::string> parceInput(const std::string &input);
  /**
   * @brief processArguments
   * @param args
   * @return
   */
  std::vector<double> processArguments(const std::vector<std::string> &args);
};

}  // namespace dev
