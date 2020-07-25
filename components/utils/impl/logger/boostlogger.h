#pragma once
#include <sstream>
#include "boost/log/trivial.hpp"
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
    //    std::stringstream ss;
    //    ss << "0x" << std::hex <<value_;;
    //    std::time_t t = std::chrono::system_clock::to_time_t(value_);
    //    auto time = std::ctime(&t);

    //    using namespace std::chrono;
    //    auto ms = duration_cast<milliseconds>(value_.time_since_epoch());
    //    auto s = duration_cast<seconds>(ms);
    //    std::time_t t = s.count();
    //    std::size_t fractional_seconds = ms.count() % 1000;
    //    std::stringstream ss;
    //    ss << std::asctime(&t);
    return boost::log::attributes::make_attribute_value(
        format_time_point(value_));
  }
  TimePoint value_;
};

class BoostLogger : public Logger<std::string, void> {
 public:
  typedef std::string LocationInfo;

  BoostLogger();

  void Init(void* unused = 0) override;
  void DeInit() override {}
  void Enable() override {}
  bool Enabled() override {
    return true;
  }
  void Disable() override {}
  void Flush() override {}
  void PushLog(const LogMessageImpl& log_message) override;

 private:
  AttributeImpl<TimePoint>* time_stamp_impl_;
  AttributeImpl<std::thread::id>* thread_id_attribute_impl_;
  AttributeImpl<std::string>* location_info_impl_;
};
