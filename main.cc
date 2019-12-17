#include "project.h"
#include "calc_exceptions.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

constexpr int valid_result_number = 1;

int main() {
    std::cout << "Enter input for calculator or 'q' for quit:" << std::endl;
    std::string input;
    const std::unique_ptr<dev::IProject> proj = std::make_unique<dev::Project>();
    do {
      getline(std::cin, input);
      try {
          const auto & result = proj->process(input);
          if (result.size() == valid_result_number) {
            std::cout << result.back() << std::endl;
          } else if (result.size() > valid_result_number) {
            std::cerr << "Invalid operations number!" << std::endl;
          } else {
            std::cerr << "Internal logic error, result is empty!" << std::endl;
          }
          // TODO: propagate unparces symbol
      } catch ( const std::invalid_argument &) {
          std::cerr << "Exception: argument is nor number niether operator!" << std::endl;
      } catch (const std::exception & e) {
          std::cerr << "Exception: " << e.what() << std::endl;
      }
    } while (input != "q");
  return 0;
}
