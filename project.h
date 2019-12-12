#pragma once
#include "iproject.h"
#include "Calculator/Calculator.h"
#include "Parser/Parser.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <limits>
#include <stack>
#include <memory>

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  Project();
  int run(const std::string& user_input);
  bool parse_string(const std::string& data);
  int calculate();


  std::vector<int> get_numbers();
  std::vector<std::string> get_operators();

 private:
  std::unique_ptr<Calculator> calculator_;
  std::unique_ptr<Parser> parser_;
};
}  // namespace dev
