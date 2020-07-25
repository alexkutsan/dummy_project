#pragma once
#include <string>
#include "utils/ilogger.h"

#ifdef USE_LOG4CXX_LOGGER
#include <log4cxx/logger.h>
class Log4CXXLogger;
typedef Log4CXXLogger ExternalLogger;
typedef log4cxx::spi::LocationInfo LocationInfo;
#define LOCATTION_INFO LOG4CXX_LOCATION
#endif

#ifdef USE_BOOST_LOGGER
class BoostLogger;
typedef BoostLogger ExternalLogger;
typedef std::string LocationInfo;
#define LOCATTION_INFO "blabla"
#endif

#ifdef USE_STD_LOGGER
class STDLogger;
typedef STDLogger ExternalLogger;
typedef std::string LocationInfo;
#define LOCATTION_INFO "blabla"
#endif

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
