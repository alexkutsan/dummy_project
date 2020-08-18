#include "project.h"
#include <dlfcn.h>
#include <functional>
#include <variant>
#include <vector>
#include "shared_lib/ishared_lib.h"
#include "utils/logger.h"

namespace dev {

CREATE_LOGGERPTR("Main");

class DeviceVisitor;
struct Device {
  virtual void print() = 0;
  virtual void accept(DeviceVisitor& visitor) = 0;
  int id_;
};

class Lamp;
class Alarm;
class ColorLamp;
struct DeviceVisitor {
  virtual void Visit(Lamp& device) = 0;
  virtual void Visit(Alarm& device) = 0;
  virtual void Visit(ColorLamp& device) = 0;
};

struct Lamp : public Device {
  virtual void On() {
    state = true;
  }
  virtual void Off() {
    state = false;
  }
  bool state;

  void print() {
    LOG_WITH_LEVEL(LogLevel::DEBUG,
                   "Ilamp " << id_ << " state " << std::boolalpha << state);
  }

  void accept(DeviceVisitor& visitor) {
    visitor.Visit(*this);
  }
};

struct Alarm : public Device {
  void Enabled() {
    state = true;
  }
  void Disable() {
    state = false;
  }
  bool state;

  void print() override {
    LOG_WITH_LEVEL(LogLevel::DEBUG,
                   "IAlarm " << id_ << " enabled " << std::boolalpha << state);
  }
  void accept(DeviceVisitor& visitor) {
    visitor.Visit(*this);
  }
};

struct ColorLamp : public Device {
  virtual void SetColor(std::string color) {
    color_ = color;
  }
  std::string color_;
  void print() override {
    LOG_WITH_LEVEL(LogLevel::DEBUG,
                   "IColorLamp " << id_ << " color " << color_);
  }
  void accept(DeviceVisitor& visitor) {
    visitor.Visit(*this);
  }
};

struct TV {
  virtual void SetChannel(std::string channel) {
    channel_ = channel;
  }
  std::string channel_;
  void print() {
    LOG_WITH_LEVEL(LogLevel::DEBUG,
                   "TV "
                       << " channel_ " << channel_);
  }
};

struct DayMode : public DeviceVisitor {
  void Visit(Lamp& device) override {
    device.Off();
  }
  void Visit(Alarm& device) override {
    device.Disable();
  }
  void Visit(ColorLamp& device) override {
    device.SetColor("RED");
  }
};

struct NightMode : public DeviceVisitor {
  void Visit(Lamp& device) override {
    device.On();
  }
  void Visit(Alarm& device) override {
    device.Enabled();
  }
  void Visit(ColorLamp& device) override {
    device.SetColor("GREEN");
  }
};

void VisitorExample() {
  std::vector<Device*> devices_;
  devices_.push_back(new Lamp);
  devices_.push_back(new ColorLamp);
  devices_.push_back(new Alarm);

  LOG_WITH_LEVEL(LogLevel::DEBUG, "\n >>>>>>>>>>> Initial state");
  for (auto& d : devices_) {
    d->print();
  }

  LOG_WITH_LEVEL(LogLevel::DEBUG, "\n >>>>>>>>>>> Set Day mode");
  DayMode day_mode;
  for (auto& d : devices_) {
    d->accept(day_mode);
    d->print();
  }

  LOG_WITH_LEVEL(LogLevel::DEBUG, "\n >>>>>>>>>>> Set Day mode");
  NightMode night_mode;
  for (auto& d : devices_) {
    d->accept(night_mode);
    d->print();
  }
}

struct STDDayMode {
  void operator()(Lamp& device) {
    device.Off();
  }
  void operator()(Alarm& device) {
    device.Disable();
  }
  void operator()(ColorLamp& device) {
    device.SetColor("RED");
  }
  void operator()(TV& device) {
    device.SetChannel("Cartoons");
  }
};

struct STDNightMode {
  void operator()(Lamp& device) {
    device.On();
  }
  void operator()(Alarm& device) {
    device.Enabled();
  }
  void operator()(ColorLamp& device) {
    device.SetColor("GTREEN");
  }
  void operator()(TV& device) {
    device.SetChannel("Adult");
  }
};

struct STDPrinter {
  void operator()(Lamp& device) {
    device.print();
  }
  void operator()(Alarm& device) {
    device.print();
  }
  void operator()(ColorLamp& device) {
    device.print();
  }
  void operator()(TV& device) {
    device.print();
  }
};

void Print(std::variant<Lamp, Alarm, ColorLamp, TV> device) {
  std::visit(STDPrinter(), device);
}

int Project::run() {
  //  VisitorExample();
  std::variant<Lamp, Alarm, ColorLamp, TV> device = Lamp();
  Print(device);
  std::variant<Lamp, Alarm, ColorLamp, TV> tv = TV();
  std::visit(STDDayMode(), tv);
  Print(tv);
  std::visit(STDNightMode(), tv);
  Print(tv);
  return 0;
}

}  // namespace dev
