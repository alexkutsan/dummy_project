#include "project.h"
#include "utils/logger.h"

// static LoggerVariable logger_("proj");
namespace dev {

CREATE_LOGGERPTR("main");

int Project::run() {
  //   logger_.Log("run");
  LOG_WITH_LEVEL(LogLevel::TRACE, "Hello");
  return 0;
}
}  // namespace dev
