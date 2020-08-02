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

template <bool use_message_loop_thread = true>
class LoggerImplementation : public Logger, public LoggerInitializer {
 public:
  LoggerImplementation()
      : impl_(nullptr), loop_thread_([this](const LogMessage& log_message) {
        std::cerr << "logger not initialized" << std::endl;
      }) {}

  void Init(std::unique_ptr<ThirdPartyLoggerInterface>&& impl) override {
    assert(impl_.get() == nullptr);
    impl_ = std::move(impl);
    impl_->Init();
    loop_thread_.setHandler(
        [this](LogMessage message) { impl_->PushLog(message); });
  }
  void DeInit() override {
    impl_->DeInit();
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
    if (use_message_loop_thread) {
      loop_thread_.Push(log_message);
    } else {
      impl_->PushLog(log_message);
    }
  }

  std::unique_ptr<ThirdPartyLoggerInterface> impl_;
  LogMessageLoopThread<LogMessage> loop_thread_;
};

Logger& Logger::instance(Logger* pre_init) {
  static Logger* instance_;
  if (pre_init) {
    assert(instance_ == nullptr);
    instance_ = pre_init;
  }
  return *instance_;
}
