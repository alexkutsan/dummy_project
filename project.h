#pragma once
#include "iproject.h"
#include "constant.h"
#include "project_operation.h"

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

    int get_error_code();

private:
    void clear_stack(stack_numbers_t&);
    value_t calculateStackValue(std::string temp_str, stack_numbers_t& stack_numbers);

    value_t take_value_from_stack();
    value_t processData(std::string& input_str);
    value_t take_value_from_stack(stack_numbers_t&);

    bool is_valid_count_value(stack_numbers_t&);
    bool is_number(const std::string& s);


    project_operation project_operation_;
    error_t error_code_val = error_code::NO_ERROR;
};
}  // namespace dev
