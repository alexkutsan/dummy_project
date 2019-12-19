#include <iostream>
#include "project.h"

int main() {
  dev::Project proj;

  auto a = proj.run("1 10 +");

  std::cout << "Result: " << a;

  return 0;
}
