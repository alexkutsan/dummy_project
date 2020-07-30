#include "shared_lib/shared_lib.h"
#include "logger/logger_impl.h"
#include "utils/logger.h"

// static LoggerVariable logger_("proj");
namespace dev {

CREATE_LOGGERPTR("Main");

int SharedLib::library_function() {
  LOG_WITH_LEVEL(LogLevel::TRACE, "Logger instance " << &Logger::instance());
  return 0;
}

}  // namespace dev

ISharedLib* Create(Logger* logger_instance) {
  Logger::instance(logger_instance);
  return new dev::SharedLib();
}
