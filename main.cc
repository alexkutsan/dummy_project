#include <boost/log/trivial.hpp>
#include "logger/log4cxxlogger.h"
#include "logger/proj_logger.h"
#include "logger/std_logger.h"
#include "project.h"

int main() {
  Log4CXXLogger logger_("log4cxx.properties");
  STDLogger std_logger;

  Logger<std::string, STDLogger>::instance().Init(
      &std_logger);  // move logger_ to Logger instance

  dev::Project p;
  return p.run();
  //  BOOST_LOG_TRIVIAL(info) << "Hello World";
  return 0;
}
