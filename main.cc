#include "run.h"
#include "project.h"
#include "calculator.h"
#include<iostream>

int main() {

  dev::Calculator calc;
  std::string s;
  std::cout<<"Enter the string: ";
  std::getline(std::cin,s);
  std::cout<<"Result:"<<calc.evaluate(s)<<std::endl;

  dev::Project p;
  return run(p);
}
