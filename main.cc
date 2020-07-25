
#include <boost/log/trivial.hpp>
#include "logger/boostlogger.h"
//#include "logger/log4cxxlogger.h"
#include "logger/proj_logger.h"
#include "logger/std_logger.h"
#include "project.h"

int main() {
  //  Log4CXXLogger log4cxx_logger_("log4cxx.properties");
  //  STDLogger std_logger;
  BoostLogger boost_logger;

  Logger<BoostLogger::LocationInfo, BoostLogger>::instance().Init(
      &boost_logger);  // move logger_ to Logger instance

  dev::Project p;
  return p.run();
  //  BOOST_LOG_TRIVIAL(info) << "Hello World";
  return 0;
}
