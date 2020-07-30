#pragma once
#include <sstream>
#include <string>
#include "utils/ilogger.h"

#define LOCATTION_INFO       \
  LocationInfo {             \
    "file", "FUNC", __LINE__ \
  }

//#ifdef USE_LOG4CXX_LOGGER
//#include <log4cxx/logger.h>
// class Log4CXXLogger;
// typedef Log4CXXLogger ExternalLogger;
//#endif

//#ifdef USE_BOOST_LOGGER
// class BoostLogger;
// typedef BoostLogger ExternalLogger;
//#endif

//#ifdef USE_STD_LOGGER
// class STDLogger;
// typedef STDLogger ExternalLogger;
//#endif

#define CREATE_LOGGERPTR(logger_name)      \
  namespace {                              \
  static std::string logger_(logger_name); \
  }

#define LOG_WITH_LEVEL(logLevel, logEvent)                        \
  do {                                                            \
    auto location = LOCATTION_INFO;                               \
    auto thread_id = std::this_thread::get_id();                  \
    std::stringstream ss;                                         \
    ss << logEvent;                                               \
    LogMessage message{logger_,                                   \
                       logLevel,                                  \
                       ss.str(),                                  \
                       std::chrono::high_resolution_clock::now(), \
                       location,                                  \
                       thread_id};                                \
    Logger::instance().PushLog(message);                          \
  } while (false)

#undef LOG4CXX_TRACE
#define LOG4CXX_TRACE(loggerPtr, logEvent) \
  LOG_WITH_LEVEL(loggerPtr, ::log4cxx::Level::getTrace(), logEvent)
