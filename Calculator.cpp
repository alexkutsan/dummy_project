#include "Calculator.h"
#include <iostream>

Calculator::Calculator(Stack &stk) : stk_(stk)
{}

double Calculator::exe() {

    std::vector<long double> numbers;
    double rec = 0;
    for(;;) {
        int rc;
        Token t = stk_.pop(rc);
        if(t.is_number()) {
            numbers.push_back(t.getNumber());
        } else { //operation

            long double result = numbers[0];
            for(int i = 1; i < numbers.size(); ++i) {

                switch (t.getOperand()) {
                case TOper::ADD:
                    result += numbers[i];
                    break;
                case TOper::SUB:
                    result -= numbers[i];
                    break;
                case TOper::MUL:
                    result *= numbers[i];
                    break;
                case TOper::DIV:
                    result /= numbers[i];
                    break;
                default:
                    std::cout << "exe error" << std::endl;
                    break;
                }
            }
            numbers.clear();
            Token nt(true, TOper::NONE, result);
            stk_.push(nt);
            std::cout << result << std::endl;
            rec = result;
        }

        if(!rc) break;
    }
    return rec;
}
