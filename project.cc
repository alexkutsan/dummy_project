#include "project.h"

namespace dev {

namespace {
  const auto kError = std::numeric_limits<int>::min();
}

// TODO: Project must use separate objects for calculate() and parse_string() options
Project::Project() : parser_(new Parser()){

}

int Project::run(const std::string& user_input) {
  return parse_string(user_input) ? 
    calculate() 
    : 
    kError;
}

// TODO: Move this method to separate object.
bool Project::parse_string(const std::string& data) {
  if (!parser_) {
    return false;
  }
  return parser_->parse(data);
}

// TODO: Move this method to separate object.
int Project::calculate() {
  calculator_.reset(new Calculator(parser_->get_numbers(),
                                   parser_->get_operators()));
  return calculator_->calculate();
}

std::vector<int> Project::get_numbers() {
  return *parser_->get_numbers();
}

std::vector<std::string> Project::get_operators() {
  return *parser_->get_operators();
} 

}  // namespace dev
