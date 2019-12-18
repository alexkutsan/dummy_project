#include "Parser.h"

namespace dev {
Parser::Parser() 
  : numbers_(new types::NumbersStack()), 
    operators_(new types::OperatorsList()) {
}

bool Parser::parse(const std::string& data) {
  if (data.empty()) {
    return false;
  }

  const auto& splitted_data = split(data);
  for (const auto& user_data : splitted_data) {
    
    // Append operators list
    std::string math_operator = string_matches_operator(user_data); 
    if (!math_operator.empty()) {
      operators_->push_back(math_operator);
      continue;
    }

    // Append numbers list
    try {
      float number = std::stof(user_data);
      numbers_->push(number);
    } catch (const std::exception& exception) {
      std::cerr << "cannot convert "<< user_data << " to number!" << std::endl;
    }
  } 

  if (operators_->size() != numbers_->size() - 1) {
    return false; 
  }

  return true;
}

std::string 
Parser::string_matches_operator(const std::string& possible_operator) const {
  if (possible_operator != "*" && 
      possible_operator != "+" && 
      possible_operator != "-" && 
      possible_operator != "/") {
    return "";
  }

  return possible_operator;
}

std::vector<std::string> Parser::split(const std::string& data) const {
  std::istringstream data_stream(data);
  std::string buffer;
  std::vector<std::string> result;
  while (std::getline(data_stream, buffer, ' ')) {
    result.push_back(buffer);
  }
  return result;
}

types::NumbersStackPtr Parser::get_numbers() {
  return std::move(numbers_);
}

types::OperatorsListPtr Parser::get_operators() {
  return std::move(operators_);
} 

}
