#include "logger/log4cxxlogger.h"
#include "log4cxx/propertyconfigurator.h"

Log4CXXLogger::Log4CXXLogger(std::string filename) : filename_(filename) {}

void Log4CXXLogger::Init() {
  log4cxx::PropertyConfigurator::configure(filename_);
}

void Log4CXXLogger::Log(LogMessage<std::string> log_message) {
  log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(log_message.logger_);
  switch (log_message.log_level_) {
    case LogLevel::DEBUG:
      logger->debug(log_message.log_event_);
      break;
    case LogLevel::ERROR:
      logger->error(log_message.log_event_);
      break;
    default:
      break;
  }
}