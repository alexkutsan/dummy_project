#pragma once
#include "iproject.h"
#include "constant.h"

#include <array>
#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>


namespace dev {

using namespace polish_notation_constant;


class Project : public IProject {
    typedef error_code error_t;

    // IProject interface
 public:
    double run(std::string);

    // MOve to private section
    value_t take_value_from_stack();

    // MOve to private section
    value_t make_operation(char type_operation,
                          double left_operand,
                          double right_operand);

    int get_error_code();

private:
    value_t processData(std::string& input_str);

    bool is_valid_count_value(stack_numbers_t&);

    value_t take_value_from_stack(stack_numbers_t&);

    value_t division         (double, double);
    value_t sum              (double, double);
    value_t subtract         (double, double);
    value_t multiplication   (double, double);

    bool is_number(const std::string& s);

    void clear_stack(stack_numbers_t&);
    error_t error_code_val = error_code::NO_ERROR;
};
}  // namespace dev
