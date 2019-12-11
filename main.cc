#include "project.h"
#include <memory>

int main() {
  std::unique_ptr<dev::Project> polish_calculator(new dev::Project);
  
  auto result = polish_calculator->run();
  if (result == std::numeric_limits<int>::min()) {
    std::cout << "Error occured while calculating!" << std::endl;
  } else {
    std::cout << (int)result << std::endl;
  }

  return 0;
}
