#include "Calculator.h"
#include <iostream>

namespace dev {
  Calculator::Calculator(types::NumbersStackPtr numbers, 
                 types::OperatorsListPtr operators) 
    : numbers_(std::move(numbers))
    , operators_(std::move(operators)) { }

float Calculator::calculate() {

  if (operators_->size() != numbers_->size() - 1) {
    return types::kError; 
  }

  for(const auto& math_operator : *operators_) {
    auto left = numbers_->pop();
    auto right = numbers_->pop();
    switch(*math_operator.begin()) {
      case types::Operators::ADD: numbers_->push(add(left,right)); break;
      case types::Operators::DEC: numbers_->push(dec(left,right)); break;
      case types::Operators::DIV: numbers_->push(div(left,right)); break;
      case types::Operators::MUL: numbers_->push(mul(left,right)); break;
      default:break;
    }
  }
  return numbers_->top();
}

float Calculator::add(float first, float second) {
  return first + second;
}

float Calculator::div(float first, float second) {
  return second ? (first / second) : types::kError;
}

float Calculator::dec(float first, float second) {
  return first - second;
}

float Calculator::mul(float first, float second) {
  return first * second;
}

}
