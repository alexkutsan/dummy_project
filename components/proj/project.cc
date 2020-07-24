#include "project.h"
#include "utils/logger.h"

namespace dev {

CREATE_LOGGERPTR("Main");

int Project::run() {
  LOG_WITH_LEVEL(LogLevel::DEBUG, "Hello");
  LOG_WITH_LEVEL(LogLevel::ERROR, "Hello");
  return 0;
}

}  // namespace dev
