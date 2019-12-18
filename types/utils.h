#ifndef UTILS_H
#define UTILS_H

#include "CustomStack.h"
#include <limits>

namespace types {
  
  typedef std::unique_ptr<CustomStack<float>> NumbersStackPtr;
  typedef CustomStack<float> NumbersStack;
  typedef std::unique_ptr<std::vector<std::string>> OperatorsListPtr;
  typedef std::vector<std::string> OperatorsList;

  const auto kError = std::numeric_limits<float>::min();
}

#endif 
