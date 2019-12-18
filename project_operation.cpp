#include "project_operation.h"

project_operation::project_operation()
{

}

value_t project_operation::division(double a, double b)
{
    if (b != 0) {
        return a / b;
    } else {
        return polish_notation_constant::ERROR_VALUE;
    }
}

value_t project_operation::sum(double a, double b)
{
    return a + b;
}

value_t project_operation::subtract(double a, double b)
{
    return a - b;
}

value_t project_operation::multiplication(double a, double b)
{
    return a * b;
}

value_t project_operation::make_operation(char type_operation,
                               double left_operand,
                               double right_operand)
{
    switch(type_operation) {
        case '+':
            left_operand = sum(left_operand, right_operand);
            break;
        case '-':
            left_operand = subtract(left_operand, right_operand);
            break;
        case '*':
            left_operand = multiplication(left_operand, right_operand);
            break;
        case '/':
            left_operand = division(left_operand, right_operand);
            break;
        default:
            left_operand = ERROR_VALUE;
            break;
    }

    return left_operand;
}
