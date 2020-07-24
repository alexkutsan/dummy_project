#ifndef LOG4CXXLOGGER_H
#define LOG4CXXLOGGER_H
#include "utils/ilogger.h"
#include <log4cxx/logger.h>

class Log4CXXLogger {
public:
  Log4CXXLogger(std::string filename);
  void Init();
  void DeInit() {}
  void Enable() {}
  void Disable() {}
  void Flush() {}
  void Log(LogMessage<std::string> log_message);
  std::string filename_;
};

#endif // LOG4CXXLOGGER_H
