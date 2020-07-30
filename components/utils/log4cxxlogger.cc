#include "logger/log4cxxlogger.h"
#include "assert.h"
#include "log4cxx/propertyconfigurator.h"

Log4CXXLogger::Log4CXXLogger(std::string filename) : filename_(filename) {}

void Log4CXXLogger::Init(void* unused) {
  log4cxx::PropertyConfigurator::configure(filename_);
}

log4cxx::LevelPtr getLogLevel(LogLevel log_level) {
  switch (log_level) {
    case LogLevel::TRACE:
      return log4cxx::Level::getTrace();
    case LogLevel::DEBUG:
      return log4cxx::Level::getDebug();
    case LogLevel::INFO:
      return log4cxx::Level::getInfo();
    case LogLevel::WARNIGN:
      return log4cxx::Level::getWarn();
    case LogLevel::ERROR:
      return log4cxx::Level::getError();
    case LogLevel::FATAL:
      return log4cxx::Level::getFatal();
    default:
      assert(false);
  }
}
void Log4CXXLogger::PushLog(const LogMessage& log_message) {
  log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(log_message.logger_);

  auto location_info = log_message.location_;
  log4cxx::spi::LocationInfo log4cxx_location(
      location_info.file_name_.c_str(),
      location_info.function_info.c_str(),
      location_info.line);
  logger->forcedLog(getLogLevel(log_message.log_level_),
                    log_message.log_event_,
                    log4cxx_location);
}
