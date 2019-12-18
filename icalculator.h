#pragma once

#include <string>

namespace dev {

class ICalculator {

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
