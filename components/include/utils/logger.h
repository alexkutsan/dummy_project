#pragma once
#include <string>

#include "utils/ilogger.h"

// START Redefince for each paticular logger implementation
class STDLogger;
typedef STDLogger ExternalLogger;
typedef std::string LocationInfo;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define LOCATTION_INFO \
  std::string(__FILE__) + ":" + TOSTRING(__LINE__) + " " + std::string(__func__)
// END Redefince for each paticular logger implementation

typedef LogMessage<LocationInfo> LogMessageImpl;

#define CREATE_LOGGERPTR(logger_name)      \
  namespace {                              \
  static std::string logger_(logger_name); \
  }

#define LOG_WITH_LEVEL(logLevel, logEvent)                             \
  do {                                                                 \
    auto location = LOCATTION_INFO;                                    \
    LogMessageImpl message{logger_,                                    \
                           logLevel,                                   \
                           logEvent,                                   \
                           std::chrono::high_resolution_clock::now(),  \
                           location,                                   \
                           std::this_thread::get_id()};                \
    Logger<LocationInfo, ExternalLogger>::instance().PushLog(message); \
  } while (false)

#undef LOG4CXX_TRACE
#define LOG4CXX_TRACE(loggerPtr, logEvent) \
  LOG_WITH_LEVEL(loggerPtr, ::log4cxx::Level::getTrace(), logEvent)
