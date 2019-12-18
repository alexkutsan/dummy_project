#ifndef PROJECT_OPERATION_H
#define PROJECT_OPERATION_H
#include "constant.h"

using namespace polish_notation_constant;

class project_operation
{

public:
    project_operation();

    value_t make_operation(char type_operation,
                          double left_operand,
                          double right_operand);

    value_t division         (double, double);
    value_t sum              (double, double);
    value_t subtract         (double, double);
    value_t multiplication   (double, double);
};

#endif // PROJECT_OPERATION_H
