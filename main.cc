#include <iostream>
#include <string>
#include "calculator.h"
#include "utils.h"

int main() {
  dev::Calculator calc_obj;

  // TODO: Make UI (input/output as a separate class or state machine)
  std::cout
      << "Input string in format: \"number\" \"space\" \"number\" \"operation\""
      << std::endl;
  const std::string user_input = get_user_input();

  if (!is_user_input_correct(user_input)) {
    std::cout << "Wrong Input!!! Exiting..." << std::endl;

    return 0;
  }

  calc_obj.save_user_input(user_input);

  const float final_result = calc_obj.calculate_result();
  std::cout << "\nRESULT: " << final_result << std::endl;

  return 0;
}
