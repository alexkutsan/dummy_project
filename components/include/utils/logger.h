#pragma once
#include <string>
#include "utils/ilogger.h"

class Log4CXXLogger;

typedef std::string MyLocationInfo;
typedef Log4CXXLogger ExternalLogger;
typedef LogMessage<MyLocationInfo> LogMessageImpl;
#define LOCATTION_INFO "__LINE__"

#define CREATE_LOGGERPTR(logger_name)      \
  namespace {                              \
  static std::string logger_(logger_name); \
  }

#define LOG_WITH_LEVEL(logLevel, logEvent)                               \
  do {                                                                   \
    LogMessageImpl message{                                              \
        logger_, logLevel, logEvent, 0, LOCATTION_INFO, "main thread"};  \
    Logger<MyLocationInfo, ExternalLogger>::instance().PushLog(message); \
  } while (false)

#undef LOG4CXX_TRACE
#define LOG4CXX_TRACE(loggerPtr, logEvent) \
  LOG_WITH_LEVEL(loggerPtr, ::log4cxx::Level::getTrace(), logEvent)
