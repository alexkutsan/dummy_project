#include "project.h"

namespace dev {

namespace {
  const int kUserInputLimit = 1000;
}

Project::Project() {

}

int Project::run() {
  char user_input[kUserInputLimit];
  std::cout << "Input expression -> ";
  std::cin.getline(user_input, sizeof(user_input));
  parse_string(user_input);
  return calculate();
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
  return true;
}

int Project::calculate() {
  if (operators_.size() != numbers_.size() - 1) {
    return std::numeric_limits<int>::min(); 
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
  return first / second;
}

int Project::dec(int first, int second) {
  return first - second;
}

int Project::mul(int first, int second) {
  return first * second;
}

}  // namespace dev
