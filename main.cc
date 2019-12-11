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
      std::istringstream iss(input);
      std::vector<std::string> all_args(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>());
      if (all_args.size() > 2) {
          dev::Project proj;
          try {
              const auto & result = proj.process(all_args);
              if (result.size() == 1) {
                std::cout << result.back() << std::endl;
              } else if (result.size() > 1) {
                std::cerr << "Invalid operations number!" << std::endl;
              } else {
                std::cerr << "Internal logic error, result is empty!" << std::endl;
              }
          } catch ( const std::invalid_argument & e) {
              std::cerr << "Exception: argument cannot be cast to double!" << std::endl;
          } catch (const InvalidOperandsException & e) {
              std::cerr << "Exception: " << e.what() << std::endl;
          } catch (const InvalidOpertionException & e) {
              std::cerr << "Exception: " << e.what() << std::endl;
          } catch (const std::exception & e) {
              std::cerr << "Exception: " << e.what() << std::endl;
          }
      } else if (input != "q") {
          std::cerr << "Invalid parameters number. You must enter at least 2 operands and operation" << std::endl;
      }
    } while (input != "q");
  return 0;
}
