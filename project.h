#pragma once

#include "iproject.h"

namespace dev {

class Project : public IProject {
//friend class ProjectTest;
public:
  std::vector<double> process(const std::vector<std::string> & args) override;
// private: // todo: make private
  bool isOperator(const std::string & arg) const;
  void applyOperation(const std::string & operation,
                      std::vector<double> &operands) const;
};

}  // namespace dev
