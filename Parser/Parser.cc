#include "Parser.h"

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

namespace dev {
Parser::Parser() 
  : numbers_(new NumbersStack()), 
    operators_(new OperatorsList()) {
}

bool Parser::parse(const std::string& data) {
  if (data.empty()) {
    return false;
  }

  std::istringstream data_stream(data);
  std::string buffer;
  while (std::getline(data_stream, buffer, ' ')) {
    std::string math_operator = string_matches_operator(buffer); 
    if (!math_operator.empty()) {
      operators_->push_back(math_operator);
      continue;
    }

    try {
      int number = std::stoi(buffer);
      numbers_->push(number);
    } catch (const std::exception& exception) {
      std::cerr << "cannot convert "<< buffer << " to number!" << std::endl;
    }
  } 

  if (operators_->size() != numbers_->size() - 1) {
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

NumbersStackPtr Parser::get_numbers() {
  return std::move(numbers_);
}

OperatorsListPtr Parser::get_operators() {
  return std::move(operators_);
} 

}
