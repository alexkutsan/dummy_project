#include "project.h"
#include "calc_exceptions.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

int main() {
    std::cout << "Enter input for calculator or 'q' for quit:" << std::endl;
    std::string input;
    do {
      getline(std::cin, input);
      dev::Project proj;
      try {
          const auto & result = proj.process(input);
          if (result.size() == 1) {
            std::cout << result.back() << std::endl;
          } else if (result.size() > 1) {
            std::cerr << "Invalid operations number!" << std::endl;
          } else {
            std::cerr << "Internal logic error, result is empty!" << std::endl;
          }
      } catch ( const std::invalid_argument &) {
          std::cerr << "Exception: argument is nor number niether operator!" << std::endl;
      } catch (const std::exception & e) {
          std::cerr << "Exception: " << e.what() << std::endl;
      }
    } while (input != "q");
  return 0;
}
