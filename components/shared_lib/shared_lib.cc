#include "shared_lib/shared_lib.h"
#include "utils/logger.h"

// static LoggerVariable logger_("proj");
namespace dev {

CREATE_LOGGERPTR("Main");

int SharedLib::library_function() {
  //   logger_.Log("run");
  LOG_WITH_LEVEL(LogLevel::TRACE, "Hello from lib");
  return 0;
}
}  // namespace dev
