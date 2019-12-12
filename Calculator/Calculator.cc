#include "Calculator.h"

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

namespace dev {
  Calculator::Calculator(std::unique_ptr<std::vector<int>> numbers, 
                 std::unique_ptr<std::vector<std::string>> operators) 
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
      auto left_op = (*numbers_)[numbers_->size() - 1];
      auto right_op = (*numbers_)[numbers_->size() - 2];
      numbers_->pop_back();
      numbers_->pop_back();
      numbers_->push_back(add(left_op,right_op));
    }

    if (math_operator == "-") {
      auto left_op = (*numbers_)[numbers_->size() - 1];
      auto right_op = (*numbers_)[numbers_->size() - 2];
      numbers_->pop_back();
      numbers_->pop_back();
      numbers_->push_back(dec(left_op,right_op));
    }

    if (math_operator == "*") {
      auto left_op = (*numbers_)[numbers_->size() - 1];
      auto right_op = (*numbers_)[numbers_->size() - 2];
      numbers_->pop_back();
      numbers_->pop_back();
      numbers_->push_back(mul(left_op,right_op));
    }

    if (math_operator == "/") {
      auto left_op = (*numbers_)[numbers_->size() - 1];
      auto right_op = (*numbers_)[numbers_->size() - 2];
      numbers_->pop_back();
      numbers_->pop_back();
      numbers_->push_back(div(left_op,right_op));
    }
  }
  return *numbers_->begin();
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
