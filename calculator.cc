#include "calculator.h"
#include <algorithm>
#include <cctype>
#include <numeric>
#include <regex>
#include <vector>
#include "utils.h"

namespace dev {

void Calculator::save_user_input(const std::string& input) {
  user_input_ = input;
}

bool Calculator::is_user_input_correct(const std::string& input) {
  const std::regex input_pattern(
      R"(^(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s*([\+\-\*\/])$)");
  const bool res = std::regex_search(input, sm_, input_pattern);
  return res;
}

void Calculator::process_operands(const std::string& operand,
                                  std::vector<float>& operands) const {
  float current_val = 0;
  std::string::size_type sz;  // Alias of size_t
  current_val = std::stof(operand, &sz);
  operands.push_back(current_val);
}

float Calculator::process_operator(const std::string& operation,
                                   std::vector<float>& operands) const {
  if ("+" == operation) {
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::plus<float>());
  }

  if ("-" == operation) {
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::minus<float>());
  }

  if ("*" == operation) {
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::multiplies<float>());
  }

  if ("/" == operation) {
    if (std::any_of(operands.begin() + 1, operands.end(), compare(0))) {
      return 0;
    }
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::divides<float>());
  }
  return 0;
}

float Calculator::calculate_result() const {
  float final_res = 0;
  std::vector<float> operands;
  for (std::smatch::iterator it = sm_.begin(); it != sm_.end(); ++it) {
    const bool is_num = is_number(*it);
    const bool is_operation = is_operator(*it);

    if (is_num) {
      process_operands(*it, operands);
      continue;
    }

    if (is_operation) {
      final_res = process_operator(*it, operands);
    }
  }
  return final_res;
}

}  // namespace dev
