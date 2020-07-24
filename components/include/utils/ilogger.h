#ifndef ILOGGER_H
#define ILOGGER_H
#pragma once
#include <string>
#include <chrono>

enum class LogLevel {
  TRACE,
  DEBUG,
  ERROR
};


template<typename LocationInfo>
struct LogMessage {
  std::string logger_;
  LogLevel log_level_;
  std::string log_event_;
//  std::chrono::milliseconds timestamp_;
  int timestamp_;
  LocationInfo location_;
  std::string thread_name_;
};


template<typename LocationInfo, class ThirdPartyLogger>
class Logger {
public:
  typedef LogMessage<LocationInfo> LogMessageImpl;

  virtual void Init(ThirdPartyLogger* impl) = 0;
  virtual void DeInit()  = 0;
  virtual void Enable()  = 0;
  virtual bool Enabled() = 0;
  virtual void Disable() = 0;
  virtual void Flush() = 0;
  virtual void PushLog(const LogMessageImpl& log_message) = 0;
  static Logger<LocationInfo, ThirdPartyLogger>& instance();
};

#endif // ILOGGER_H
