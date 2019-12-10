#pragma once
#include "string"

namespace dev{

class IProject {
  virtual float run(std::string expression) = 0;
};

}
