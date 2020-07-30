#pragma once
#include "shared_lib/ishared_lib.h"
#include "utils/ilogger.h"

namespace dev {

class SharedLib : public ISharedLib {
  // IProject interface
 public:
  int library_function() override;
};

}  // namespace dev
extern "C" ISharedLib* Create(Logger* logger_instance);
