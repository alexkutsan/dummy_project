#pragma once

#include <string>

namespace dev {

class ICalculator {
  /**
   * @brief is_user_input_correct check that input correspponds
   * pattern "NUM-SPACE-NUM-SPACE-NUM-SPACE-OPERATOR"
   * @note operator can be any of "+, -, *, /"
   * @param input input to check
   * @return true if input correct, otherwise - false
   */
  virtual bool is_user_input_correct(const std::string& input) = 0;

  /**
   * @brief calculate_result calculates final result
   * @return final calculated result
   */
  virtual float calculate_result() const = 0;

  /**
   * @brief save_user_input saves user input inot internal storage
   * @param input input to save
   */
  virtual void save_user_input(const std::string& input) = 0;
};

}  // namespace dev
