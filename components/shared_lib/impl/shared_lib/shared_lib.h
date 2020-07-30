#pragma once
#include "shared_lib/ishared_lib.h"

namespace dev {

class SharedLib : public ISharedLib {
  // IProject interface
 public:
  int library_function() override;
};

extern "C" ISharedLib* Create();

}  // namespace dev
