#pragma once
#include <sstream>
#include <string>
#include "utils/ilogger.h"

#define LOCATTION_INFO       \
  LocationInfo {             \
    "file", "FUNC", __LINE__ \
  }

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
