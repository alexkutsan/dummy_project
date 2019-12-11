#pragma once
#include "iproject.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <limits>
#include <stack>

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  Project();
  int run();
  bool parse_string(const std::string& data);
  int calculate();
  const std::vector<int>& get_numbers();
  const std::vector<std::string>& get_operators();
  std::string string_matches_operator(const std::string& possible_operator); 

  int add(int first, int second);
  int div(int first, int second);
  int dec(int first, int second);
  int mul(int first, int second);
 private:
  std::vector<int> numbers_;
  std::vector<std::string> operators_;
};
}  // namespace dev
