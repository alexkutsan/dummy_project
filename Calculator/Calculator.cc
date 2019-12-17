#include "Calculator.h"
#include <iostream>

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

namespace dev {
  Calculator::Calculator(NumbersStackPtr numbers, 
                 OperatorsListPtr operators) 
    : numbers_(std::move(numbers))
    , operators_(std::move(operators)) { }

int Calculator::calculate() {

  if (operators_->size() != numbers_->size() - 1) {
    return kError; 
  }

  // TODO: Redefine numbers_ as custom stack
  // with overrided 'pop' method.
  // This will prevent double using of numbers_->pop_back()
  for(const auto& math_operator : *operators_) {
    if (math_operator == "+") {
      auto left = numbers_->pop();
      auto right = numbers_->pop();
      numbers_->push(add(left,right));
    }

    if (math_operator == "-") {
      auto left = numbers_->pop();
      auto right = numbers_->pop();
      numbers_->push(dec(left,right));
    }

    if (math_operator == "*") {
      auto left = numbers_->pop();
      auto right = numbers_->pop();
      numbers_->push(mul(left,right));
    }

    if (math_operator == "/") {
      auto left = numbers_->pop();
      auto right = numbers_->pop();
      numbers_->push(div(left,right));
    }
  }
  return numbers_->top();
}

int Calculator::add(int first, int second) {
  return first + second;
}

int Calculator::div(int first, int second) {
  return second ? first / second : kError;
}

int Calculator::dec(int first, int second) {
  return first - second;
}

int Calculator::mul(int first, int second) {
  return first * second;
}

}
