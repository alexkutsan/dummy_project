#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace {

struct compare {
  float key;
  compare(const float& i) : key(i) {}

  bool operator()(const float& i) { return (i == key); }
};

/**
 * @brief is_user_input_correct check that input correspponds
 * pattern "NUM-SPACE-NUM-SPACE-NUM-SPACE-OPERATOR"
 * @note operator can be any of "+, -, *, /"
 * @param input input to check
 * @return true if input correct, otherwise - false
 */
bool is_user_input_correct(const std::string& input) {
  const std::regex input_pattern(
      R"(^(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s*([\+\-\*\/])$)");
   // TODO: split regexp to several steps
  const bool res = std::regex_search(input, input_pattern);
  return res;
}

std::string get_user_input() {
  std::string user_input;
  std::getline(std::cin, user_input);
  return user_input;
}

bool is_operator(const std::string& val) {
  const std::regex is_operator(R"(^[\+\-\*\/]\d{0}$)");
  // TODO: regexp is overengineering
  const bool res = std::regex_search(val, is_operator);
  return res;
}

bool is_number(const std::string& value) {
  // TODO: try to use https://ru.cppreference.com/w/cpp/types/is_floating_point
  std::istringstream iss(value);
  float f;
  // noskipws flag considers leading whitespace invalid
  iss >> std::noskipws >> f;
  // Check the entire string was consumed and if either failbit or badbit is set
  return iss.eof() && !iss.fail();
}

//bool is_number_ref(const std::string& value) {
//  try {
//     std::stof(value);
//     return true;
//  } catch (std::logic_error e){
//     return false;
//  }
//}

}  // namespace
#endif  // UTILS_H
