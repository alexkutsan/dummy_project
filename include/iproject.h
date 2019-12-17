#pragma once
#include "string"

namespace dev{

class IProject {
  virtual float run(const std::string& expression) = 0;
};

}
