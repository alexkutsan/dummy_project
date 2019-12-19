#include "project.h"
#include "Stack.h"
#include "Token.h"
#include "Calculator.h"
#include "Parser.h"

#include <iostream>

namespace dev {

void Project::stackTest()
{
    /*
    std::cout << "stack" << std::endl;
    std::vector<Token> tk;
    tk.push_back(Token(true, TOper::NONE, 3));
    tk.push_back(Token(true, TOper::NONE, 2));
    tk.push_back(Token(true, TOper::PLUS, 0));
    Stack stk(tk);
    std::cout << "test" << std::endl;
    */
}

int Project::run() {
  stackTest();
      std::cout << "rrrrrrrrun" << std::endl;
  return 0;
}
}  // namespace dev
