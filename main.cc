#include "logger/logger_impl.h"
#include "project.h"
#include "utils/external_logger.h"

int main() {
#ifdef USE_LOG4CXX_LOGGER
  auto logger_ = std::make_unique<Log4CXXLogger>("log4cxx.properties");
#endif
#ifdef USE_BOOST_LOGGER
  auto logger_ = std::make_unique<BoostLogger>();
#endif
#ifdef USE_STD_LOGGER
  auto logger_ = std::make_unique<STDLogger>();
#endif

  auto logger_impl_ = new LoggerImplementation<false>();
  logger_impl_->Init(std::move(logger_));
  Logger::instance(logger_impl_);  // move logger_ to Logger instance

  dev::Project p;
  return p.run();
  return 0;
}
