#ifdef USE_BOOST_LOGGER
#include "logger/boostlogger.h"
#endif
#ifdef USE_LOG4CXX_LOGGER
#include "logger/log4cxxlogger.h"
#endif
#ifdef USE_STD_LOGGER
#include "logger/std_logger.h"
#endif

#include "logger/logger_impl.h"

#include "project.h"

int main() {
#ifdef USE_LOG4CXX_LOGGER
  Log4CXXLogger logger_("log4cxx.properties");
  typedef Logger<Log4CXXLogger::LocationInfo, Log4CXXLogger> LoggerType;
#endif
#ifdef USE_BOOST_LOGGER
  BoostLogger logger_;
  typedef Logger<BoostLogger::LocationInfo, BoostLogger> LoggerType;
#endif
#ifdef USE_STD_LOGGER
  STDLogger logger_;
  typedef Logger<STDLogger::LocationInfo, STDLogger> LoggerType;
#endif

  LoggerType::instance().Init(&logger_);  // move logger_ to Logger instance

  dev::Project p;
  return p.run();
  //  BOOST_LOG_TRIVIAL(info) << "Hello World";
  return 0;
}
