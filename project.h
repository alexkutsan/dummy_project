#pragma once
#include "iproject.h"
#include "fixed_queue.h"
#include "string_generator.h"

#include <vector>
#include <string>
#include <sstream>

namespace dev {

class Project : public IProject {
  // IProject interface
 public:
  float run(std::string expression = "");

 private:
    FixedSizeQueue _queue;
};
}  // namespace dev
