#pragma once
#include <boost/log/trivial.hpp>
#include <sstream>
#include "utils/ilogger.h"

template <typename ValueType>
class AttributeImpl : public boost::log::attribute::impl {
 public:
  // The method generates a new attribute value
  boost::log::attribute_value get_value() {
    return boost::log::attributes::make_attribute_value(value_);
  }
  ValueType value_;
};

template <>
class AttributeImpl<std::thread::id> : public boost::log::attribute::impl {
 public:
  // The method generates a new attribute value
  boost::log::attribute_value get_value() {
    std::stringstream ss;
    ss << "0x" << std::hex << value_;
    ;
    return boost::log::attributes::make_attribute_value(ss.str());
  }
  std::thread::id value_;
};

std::string format_time_point(
    std::chrono::high_resolution_clock::time_point point);

template <>
class AttributeImpl<TimePoint> : public boost::log::attribute::impl {
 public:
  // The method generates a new attribute value
  boost::log::attribute_value get_value() {
    return boost::log::attributes::make_attribute_value(
        format_time_point(value_));
  }
  TimePoint value_;
};

class BoostLogger : public ThirdPartyLoggerInterface {
 public:
  BoostLogger();

  void Init() override;
  void DeInit() override {}
  void Enable() override {}
  bool Enabled() override {
    return true;
  }
  void Disable() override {}
  void Flush() override {}
  void PushLog(const LogMessage& log_message) override;

 private:
  AttributeImpl<TimePoint>* time_stamp_impl_;
  AttributeImpl<std::thread::id>* thread_id_attribute_impl_;
  AttributeImpl<LocationInfo>* location_info_impl_;
};
