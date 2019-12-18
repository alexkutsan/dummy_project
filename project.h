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
#include "CustomStack.h"

namespace dev {

class Project : public IProject {
 public:
  Project();
  float run(const std::string& user_input);

 private:
  std::unique_ptr<Calculator> calculator_;
  std::unique_ptr<Parser> parser_;
};
}  // namespace dev
