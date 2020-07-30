#ifndef LOG4CXXLOGGER_H
#define LOG4CXXLOGGER_H
#include <log4cxx/logger.h>
#include "utils/ilogger.h"

class Log4CXXLogger : public ThirdPartyLoggerInterface {
 public:
  Log4CXXLogger(std::string filename);
  void Init(void* unused = 0);
  void DeInit() {}
  void Enable() {}
  bool Enabled() {
    return true;
  }
  void Disable() {}
  void Flush() {}
  void PushLog(const LogMessage& log_message);
  std::string filename_;
};

#endif  // LOG4CXXLOGGER_H
