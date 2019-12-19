#pragma once
#include "iproject.h"

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  int run();
  void stackTest();
};
}  // namespace dev
