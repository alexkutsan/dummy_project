#include "project.h"

namespace dev {

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

Project::Project() {

}

int Project::run(const std::string& user_input) {
  return parse_string(user_input) ? 
    calculate() 
    : 
    kError;
}

bool Project::parse_string(const std::string& data) {
  if (data.empty()) {
    return false;
  }
 
  numbers_.clear();
  operators_.clear();

  std::istringstream data_stream(data);
  std::string buffer;
  while (std::getline(data_stream, buffer, ' ')) {
    std::string math_operator = string_matches_operator(buffer); 
    if (!math_operator.empty()) {
      operators_.push_back(math_operator);
    }

    try {
      int number = std::stoi(buffer);
      numbers_.push_back(number);
    } catch (const std::exception& exception) {
      // KEK
    }
  } 

  if (numbers_.empty() || operators_.empty()) {
    return false;
  }

  return true;
}

int Project::calculate() {
  if (operators_.size() != numbers_.size() - 1) {
    return kError; 
  }

  for(const auto& math_operator : operators_) {
    if (math_operator == "+") {
      auto left_op = numbers_[numbers_.size() - 1];
      auto right_op = numbers_[numbers_.size() - 2];
      numbers_.pop_back();
      numbers_.pop_back();
      numbers_.push_back(add(left_op,right_op));
    }

    if (math_operator == "-") {
      auto left_op = numbers_[numbers_.size() - 1];
      auto right_op = numbers_[numbers_.size() - 2];
      numbers_.pop_back();
      numbers_.pop_back();
      numbers_.push_back(dec(left_op,right_op));
    }

    if (math_operator == "*") {
      auto left_op = numbers_[numbers_.size() - 1];
      auto right_op = numbers_[numbers_.size() - 2];
      numbers_.pop_back();
      numbers_.pop_back();
      numbers_.push_back(mul(left_op,right_op));
    }

    if (math_operator == "/") {
      auto left_op = numbers_[numbers_.size() - 1];
      auto right_op = numbers_[numbers_.size() - 2];
      numbers_.pop_back();
      numbers_.pop_back();
      numbers_.push_back(div(left_op,right_op));
    }
  }
  return *numbers_.begin();
}

const std::vector<int>& Project::get_numbers() {
  return numbers_;
}

const std::vector<std::string>& Project::get_operators() {
  return operators_;
}

std::string Project::string_matches_operator(const std::string& possible_operator) {
  if (possible_operator != "*" && possible_operator != "+" && possible_operator != "-" && possible_operator != "/") {
    return "";
  }
  return possible_operator;
}

int Project::add(int first, int second) {
  return first + second;
}

int Project::div(int first, int second) {
  return second ? first / second : kError;
}

int Project::dec(int first, int second) {
  return first - second;
}

int Project::mul(int first, int second) {
  return first * second;
}

}  // namespace dev
