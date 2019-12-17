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

  bool operator()(const float& i) {
    return (i == key);
  }
};

std::string get_user_input() {
  std::string user_input;
  std::getline(std::cin, user_input);
  return user_input;
}

bool is_operator(const std::string& val) {
  const std::regex is_operator(R"(^[\+\-\*\/]\d{0}$)");
  const bool res = std::regex_search(val, is_operator);
  return res;
}

bool is_number(const std::string& value) {
  std::istringstream iss(value);
  float f;
  // noskipws flag considers leading whitespace invalid
  iss >> std::noskipws >> f;
  // Check the entire string was consumed and if either failbit or badbit is set
  return iss.eof() && !iss.fail();
}

}  // namespace
#endif  // UTILS_H
