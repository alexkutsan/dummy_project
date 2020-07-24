#include "components/proj/include/project.h"
#include "components/utils/include/utils/logger/proj_logger.h"
#include "components/utils/std_logger.h"

// LoggerImplementation& LoggerImplementation::instance() {
//  static LoggerImplementation logger_;
//  return logger_;
//}

int main() {
  STDLogger logger_;
  Logger<std::string, STDLogger>::instance().Init(&logger_);

  dev::Project p;
  return p.run();
}
