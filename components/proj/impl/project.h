#pragma once
#include "proj/iproject.h"

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  int run();
};
}  // namespace dev
