#include "run.h"
#include "project.h"
#include "calculator.h"

#include <iostream>

int main() {

  dev::Calculator c;
  std::cout << c.calc("((2.5 + 2.5) * 9.0) / 3.0") << std::endl;
  // return c.calc("");

  dev::Project p;
  return run(p);
}
