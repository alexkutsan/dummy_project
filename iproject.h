#pragma once
#include <string>

namespace dev{

class IProject {
  virtual int run(const std::string& user_input) = 0;
};

}
