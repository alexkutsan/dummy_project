#ifndef ILOGGER_H
#define ILOGGER_H
#pragma once
#include <chrono>
#include <string>
#include <thread>
enum class LogLevel { TRACE, DEBUG, INFO, WARNIGN, ERROR, FATAL };

typedef std::chrono::high_resolution_clock::time_point TimePoint;

struct LocationInfo {
  std::string file_name_;
  std::string function_info;
  int line;
};

struct LogMessage {
  std::string logger_;  // <- component_name
  LogLevel log_level_;
  std::string log_event_;
  TimePoint timestamp_;
  LocationInfo location_;
  std::thread::id thread_id_;
};

template <class ThirdPartyLogger>
class LoggerInitializer {
 public:
  virtual void Init(ThirdPartyLogger* impl) = 0;
  virtual void DeInit() = 0;
};

class Logger {
 public:
  virtual void Enable() = 0;
  virtual bool Enabled() = 0;
  virtual void Disable() = 0;
  virtual void Flush() = 0;
  virtual void PushLog(const LogMessage& log_message) = 0;
  static Logger& instance(Logger* pre_init = nullptr);
  //  static void init_singleton(Logger<ThirdPartyLogger>* instance);
};

class ThirdPartyLoggerInterface : public Logger,
                                  public LoggerInitializer<void> {};
#endif  // ILOGGER_H
