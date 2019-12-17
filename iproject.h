#pragma once
#include <vector>
#include <string>

namespace dev{
class IProject {
public:
    /**
   * @brief process applies math operations from args to operands from arfs
   * @param args list of ordered arguments and operations
   * @return calculation result
   */
  virtual std::vector<double> process(const std::string & args) = 0;
};

}
