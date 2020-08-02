#pragma once
#include "utils/ilogger.h"

class STDLogger : public ThirdPartyLoggerInterface {
 public:
  STDLogger();

  void Init() override;
  void DeInit() override;
  void Enable() override;
  bool Enabled() override {
    return true;
  }
  void Disable() override;
  void Flush() override;
  void PushLog(const LogMessage& log_message) override;

 private:
  bool enable_;
};
