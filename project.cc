#include "project.h"

namespace dev {

namespace {
  const auto kError = std::numeric_limits<float>::min();
}

Project::Project() {
}

float Project::run(const std::string& user_input) {
  parser_.reset(new Parser());
  const bool parsing_successful = parser_->parse(user_input);
  if (!parsing_successful) {
    return kError;
  }

  calculator_.reset(new Calculator(parser_->get_numbers(),
                                   parser_->get_operators()));
  return calculator_->calculate();
}

}  // namespace dev
