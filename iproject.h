#pragma once
#include <vector>
#include <string>

namespace dev{

class IProject {
  virtual std::vector<double> process(const std::string & args) = 0;
};

}
