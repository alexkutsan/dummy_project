#pragma once
#include "icalculator.h"

#include <regex>
#include <string>

namespace dev {

class Calculator : public ICalculator {
 public:
  bool is_user_input_correct(const std::string& input) override;
  float calculate_result() const override;
  void save_user_input(const std::string& input) override;
  void process_operands(const std::string& operand,
                        std::vector<float>& operands) const;
  float process_operator(const std::string& operation,
                         std::vector<float>& operands) const;

 private:
  std::string user_input_;
  std::smatch sm_;
};
}  // namespace dev
