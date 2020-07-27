#include "run.h"
#include "rpncalculator.h"
#include <string>

int main() {
  dev::RPNCalculator calculator;
  std::string expr = "4 12 3 + * 2 / 5 5 + * 100 2 * - 2 /";
  calculator.addExpression(expr);
  return run(calculator);
}
