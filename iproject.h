#pragma once
#include <vector>
#include <string>

namespace dev{
// TODO: remove interface as not needed
class IProject {
public:
  virtual std::vector<double> process(const std::string & args) = 0;
};

}
