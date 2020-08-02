
#include "impl/logger/boostlogger.h"

#include "boost/log/trivial.hpp"
#include "boost/log/utility/setup.hpp"

BoostLogger::BoostLogger() {}

template <typename ValueType>
class Attribute : public boost::log::attribute {
 public:
  Attribute(AttributeImpl<ValueType>* impl) : boost::log::attribute(impl) {}
  // Attribute casting support
  explicit Attribute(boost::log::attributes::cast_source const& source)
      : boost::log::attribute(source.as<AttributeImpl<ValueType> >()) {}
};

void BoostLogger::Init() {
  namespace logging = boost::log;
  namespace src = boost::log::sources;
  namespace sinks = boost::log::sinks;
  namespace keywords = boost::log::keywords;

  static const std::string COMMON_FMT(
      "[%Severity%][%TimeStamp%][%ThreadID%] %Location% : %Message%");

  boost::log::register_simple_formatter_factory<
      boost::log::trivial::severity_level,
      char>("Severity");

  time_stamp_impl_ = new AttributeImpl<TimePoint>();
  logging::core::get()->add_global_attribute(
      "TimeStamp",
      Attribute<typeof(time_stamp_impl_->value_)>(time_stamp_impl_));

  thread_id_attribute_impl_ = new AttributeImpl<std::thread::id>();
  logging::core::get()->add_global_attribute(
      "ThreadID", Attribute<std::thread::id>(thread_id_attribute_impl_));

  location_info_impl_ = new AttributeImpl<LocationInfo>();
  logging::core::get()->add_global_attribute(
      "Location", Attribute<LocationInfo>(location_info_impl_));

  boost::log::add_console_log(std::cout,
                              boost::log::keywords::format = COMMON_FMT,
                              boost::log::keywords::auto_flush = true);

  //  // Output message to file, rotates when file reached 1mb or at midnight
  //  every
  //  // day. Each log file is capped at 1mb and total is 20mb
  boost::log::add_file_log(
      boost::log::keywords::file_name = "sample_%3N.log",
      boost::log::keywords::rotation_size = 1 * 1024 * 1024,
      boost::log::keywords::max_size = 20 * 1024 * 1024,
      boost::log::keywords::time_based_rotation =
          boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
      boost::log::keywords::format = COMMON_FMT,
      boost::log::keywords::auto_flush = true);
}

void BoostLogger::PushLog(const LogMessage& log_message) {
  // Output some simple log message
  location_info_impl_->value_ = log_message.location_;
  thread_id_attribute_impl_->value_ = log_message.thread_id_;
  time_stamp_impl_->value_ = log_message.timestamp_;
  switch (log_message.log_level_) {
    case LogLevel::TRACE:
      BOOST_LOG_TRIVIAL(trace) << log_message.log_event_;
      break;
    case LogLevel::DEBUG:
      BOOST_LOG_TRIVIAL(debug) << log_message.log_event_;
      break;
    case LogLevel::INFO:
      BOOST_LOG_TRIVIAL(info) << log_message.log_event_;
      break;
    case LogLevel::WARNIGN:
      BOOST_LOG_TRIVIAL(warning) << log_message.log_event_;
      break;
    case LogLevel::ERROR:
      BOOST_LOG_TRIVIAL(error) << log_message.log_event_;
      break;
    case LogLevel::FATAL:
      BOOST_LOG_TRIVIAL(fatal) << log_message.log_event_;
      break;
    default:
      assert(false);
  }
}

std::string format_time_point(
    std::chrono::high_resolution_clock::time_point point) {
  using namespace std::chrono;
  static_assert(system_clock::time_point::period::den == 1000000000 &&
                system_clock::time_point::period::num == 1);
  std::string out(29, '0');
  char* buf = &out[0];
  std::time_t now_c = system_clock::to_time_t(point);
  std::strftime(buf, 21, "%Y-%m-%dT%H:%M:%S.", std::localtime(&now_c));
  sprintf(buf + 20, "%09ld", point.time_since_epoch().count() % 1000000000);
  return out;
}
