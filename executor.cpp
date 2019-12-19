#include "executor.h"

#include "Parser.h"
#include "Stack.h"
#include "Calculator.h"
#include "executor.h"

double execute(const std::vector <std::string>& src)
{
    Parser p(src);
    p.parse();
    Stack stk(p.getTokens());
    //std::cout << "test" << std::endl;
    Calculator calc(stk);
    return calc.exe();
}
