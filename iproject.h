#pragma once
#include <string>

namespace dev{

class IProject {
  virtual int run(const std::string& user_input) = 0;
  virtual bool parse_string(const std::string& data) = 0;
  virtual int calculate() = 0;
};

}
