#pragma once

#include <string>

namespace dev{

// ICaculator interface
class ICalculator {
public:
  virtual double calc(std::string expression) = 0;
};

}
