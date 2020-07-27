#include "run.h"
#include "project.h"
#include "calculator.h"

#include <iostream>

int main() {

  dev::Calculator c;
  std::cout << c.calc("4 12 3 + * 2 / 5 5 + * 100 2 * - 2 /") << std::endl;
  // return c.calc("");

  dev::Project p;
  return run(p);
}
