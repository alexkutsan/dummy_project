#pragma once
#include "iproject.h"
#include "string"

namespace dev
{

  class Project : public IProject
  {
    // IProject interface
  public:
    int run();
  };
} // namespace dev
