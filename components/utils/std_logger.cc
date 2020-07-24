#include "logger/std_logger.h"
#include <iostream>

STDLogger::STDLogger() : enable_(true) {}

void STDLogger::Init() {
  std::cout << "std:logger init" << std::endl;
}

void STDLogger::DeInit() {
  std::cout << "std:logger deinit" << std::endl;
}

void STDLogger::Enable() {
  enable_ = true;
}

void STDLogger::Disable() {
  enable_ = false;
}

void STDLogger::Flush() {
  std::cout << "std:logger flusheed" << std::endl;
}

void STDLogger::Log(LogMessage<std::string> log_message) {
  if (enable_) {
    std::cout << ">> " << log_message.log_event_ << std::endl;
  } else {
    std::cout << "logger disabled" << std::endl;
  }
}
