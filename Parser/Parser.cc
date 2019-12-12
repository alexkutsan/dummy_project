#include "Parser.h"

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

namespace dev {
Parser::Parser() 
  : numbers_(new std::vector<int>()), 
    operators_(new std::vector<std::string>()) {
}

bool Parser::parse(const std::string& data) {
  if (data.empty()) {
    return false;
  }

  numbers_->clear();
  operators_->clear();

  std::istringstream data_stream(data);
  std::string buffer;
  while (std::getline(data_stream, buffer, ' ')) {
    std::string math_operator = string_matches_operator(buffer); 
    if (!math_operator.empty()) {
      operators_->push_back(math_operator);
    }

    try {
      int number = std::stoi(buffer);
      numbers_->push_back(number);
    } catch (const std::exception& exception) {
      // KEK

      // TODO: Figure out how to handle this exception
      // (if it should be)
    }
  } 

  if (numbers_->empty() || operators_->empty()) {
    return false;
  }

  return true;
}

std::string Parser::string_matches_operator(const std::string& possible_operator) {
  if (possible_operator != "*" && 
      possible_operator != "+" && 
      possible_operator != "-" && 
      possible_operator != "/") {
    return "";
  }

  return possible_operator;
}

std::unique_ptr<std::vector<int>> Parser::get_numbers() {
  return std::move(numbers_);
}

std::unique_ptr<std::vector<std::string>> Parser::get_operators() {
  return std::move(operators_);
} 

}
