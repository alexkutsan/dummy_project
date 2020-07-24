#pragma once
#include "utils/ilogger.h"

#include <functional>
#include <iostream>
#include <assert.h>


template<typename T>
class LogMessageLoopThread {
public:
  LogMessageLoopThread(std::function<void(T)> handler):
    handler_(handler) {}

  void Push(T val) {
    handler_(val);
  }
  void setHandler(const std::function<void (T)>& handler){
    handler_ = handler;
  }

private:
  std::function<void(T)> handler_;
};

template<typename LocationInfo, class ThirdPartyLogger>
class LoggerImplementation : public Logger<LocationInfo, ThirdPartyLogger> {
  typedef LogMessage<LocationInfo> LogMessageImpl;
public:
  LoggerImplementation()
      : impl_(nullptr), loop_thread_(
                       [this](LogMessageImpl log_message){
    std::cerr << "logger not initialized" << std::endl;
  }) {}

  void Init(ThirdPartyLogger* impl) override {
    assert(impl_ == nullptr);
    impl_ = impl;
    impl_->Init();
    loop_thread_.setHandler([this](LogMessageImpl message) {
      impl_->Log(message);
    });
  }
  void DeInit() override {
     impl_->DeInit();
  }
  void Enable() {
     impl_->Enable();
  }
  bool Enabled() override {
    return false;
  }
  void Disable() override {
     impl_->Disable();
  }
  void Flush() override {
     impl_->Flush();
  }

  void PushLog(const LogMessageImpl& log_message) override {
    loop_thread_.Push(log_message);
  }

  ThirdPartyLogger* impl_;
  LogMessageLoopThread<LogMessageImpl> loop_thread_;
};

template<typename LocationInfo, typename ThirdPartyLogger>
Logger<LocationInfo, ThirdPartyLogger>&
Logger<LocationInfo, ThirdPartyLogger>::instance(){
   static LoggerImplementation<LocationInfo, ThirdPartyLogger> inst;
   return inst;
 }
