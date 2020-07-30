#pragma once
#include "utils/ilogger.h"

#include <assert.h>
#include <functional>
#include <iostream>

template <typename T>
class LogMessageLoopThread {
 public:
  LogMessageLoopThread(std::function<void(T)> handler)
      : blocking_call_(handler) {}

  void Push(T val) {
    // Should post message in queue to call blocking_call_ in separate thread
    blocking_call_(val);
  }

  void setHandler(const std::function<void(T)>& force_log) {
    blocking_call_ = force_log;
  }

 private:
  std::function<void(T)> blocking_call_;
};

template <class ThirdPartyLogger>
class LoggerImplementation : public Logger,
                             public LoggerInitializer<ThirdPartyLogger> {
 public:
  LoggerImplementation()
      : impl_(nullptr), loop_thread_([this](const LogMessage& log_message) {
        std::cerr << "logger not initialized" << std::endl;
      }) {}

  void Init(ThirdPartyLogger* impl) override {
    assert(impl_ == nullptr);
    impl_ = impl;
    impl_->Init();
    loop_thread_.setHandler(
        [this](LogMessage message) { impl_->PushLog(message); });
  }
  void DeInit() override {
    //    impl_->DeInit();
  }
  void Enable() {
    return impl_->Enable();
  }

  bool Enabled() override {
    return impl_->Enabled();
  }

  void Disable() override {
    impl_->Disable();
  }
  void Flush() override {
    impl_->Flush();
  }

  void PushLog(const LogMessage& log_message) override {
    loop_thread_.Push(log_message);
    // Optional to use blocking call :
    //    impl_->Log(log_message);
  }

  ThirdPartyLogger* impl_;
  LogMessageLoopThread<LogMessage> loop_thread_;
  //  static LoggerImplementation<ThirdPartyLogger>* instance_;
};

// template <class ThirdPartyLogger>
// void Logger<ThirdPartyLogger>::init_singleton(
//    Logger<ThirdPartyLogger>* instance) {
//  LoggerImplementation<ThirdPartyLogger>::instance_ = instance;
//}

Logger& Logger::instance(Logger* pre_init) {
  static Logger* instance_ = nullptr;
  if (pre_init) {
    assert(instance_ == nullptr);
    instance_ = pre_init;
  }
  return *instance_;
}
