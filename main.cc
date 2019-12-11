#include "project.h"
#include <memory>


namespace {
  const int kUserInputLimit = 1000;
}

//TODO: Maybe add IO handler ??
std::string handle_input() {
  char user_input[kUserInputLimit];
  std::cout << "Input expression -> ";
  std::cin.getline(user_input, sizeof(user_input));
  return std::string(user_input);
}

void handle_output(int result) {
  if (result == std::numeric_limits<int>::min()) {
    std::cout << "Error occured while calculating!" << std::endl;
  } else {
    std::cout << (int)result << std::endl;
  }
}

int main() {
  std::unique_ptr<dev::Project> polish_calculator(new dev::Project);
  int result = polish_calculator->run(handle_input());
  handle_output(result);
  return 0;
}
