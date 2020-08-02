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
  std::string component_;
  LogLevel log_level_;
  std::string log_event_;
  TimePoint timestamp_;
  LocationInfo location_;
  std::thread::id thread_id_;
};

class Logger {
 public:
  virtual void Enable() = 0;
  virtual bool Enabled() = 0;
  virtual void Disable() = 0;
  virtual void Flush() = 0;
  virtual void PushLog(const LogMessage& log_message) = 0;
  static Logger& instance(Logger* pre_init = nullptr);
};

class ThirdPartyLoggerInterface : public Logger {
 public:
  virtual void Init() = 0;
  virtual void DeInit() = 0;
};

class LoggerInitializer {
 public:
  virtual void Init(std::unique_ptr<ThirdPartyLoggerInterface>&& impl) = 0;
  virtual void DeInit() = 0;
};

#endif  // ILOGGER_H
