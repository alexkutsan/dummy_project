#pragma once
#include "utils/ilogger.h"

class STDLogger {
public:
  STDLogger();

  void Init() ;
  void DeInit() ;
  void Enable() ;
  bool Enabled() {
    return true;
  }
  void Disable() ;
  void Flush() ;
  void Log(LogMessage<std::string> log_message);
private:
  bool enable_;
};

typedef std::string MyLocationInfo;
typedef STDLogger ExternalLogger;
typedef LogMessage<MyLocationInfo> LogMessageImpl;
#define LOCATTION_INFO "line"



