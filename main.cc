#include "logger/logger_impl.h"
#include "project.h"
#include "utils/external_logger.h"

int main() {
#ifdef USE_LOG4CXX_LOGGER
  Log4CXXLogger logger_("log4cxx.properties");
  typedef LoggerImplementation<Log4CXXLogger> LoggerType;
#endif
#ifdef USE_BOOST_LOGGER
  BoostLogger logger_;
  typedef LoggerImplementation<BoostLogger> LoggerType;
#endif
#ifdef USE_STD_LOGGER
  STDLogger logger_;
  typedef LoggerImplementation<STDLogger> LoggerType;
#endif

  LoggerType logger_impl_;
  logger_impl_.Init(&logger_);
  Logger::instance(&logger_impl_);  // move logger_ to Logger instance

  dev::Project p;
  return p.run();
  //  BOOST_LOG_TRIVIAL(info) << "Hello World";
  return 0;
}
