#include "logger/log4cxxlogger.h"
#include "logger/proj_logger.h"
#include "logger/std_logger.h"
#include "project.h"

int main() {
  Log4CXXLogger logger_("log4cxx.properties");
  Logger<std::string, Log4CXXLogger>::instance().Init(&logger_);

  dev::Project p;
  return p.run();
}
