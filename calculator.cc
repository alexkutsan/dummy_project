#include "calculator.h"
#include <algorithm>
#include <cctype>
#include <numeric>
#include <regex>
#include <vector>
#include "utils.h"


namespace dev {

//void Calculator::save_user_input(const std::string& input) {
//    // ** Method checks if input is correct and saves string inserted.
//    // ** Shoud be devided into two separate methods
//  const std::regex input_pattern(
//      R"(^(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s*([\+\-\*\/])$)");
//  const bool res = std::regex_search(input, sm_, input_pattern);
//  if (res) {
//    user_input_ = input;
//  }
//}
//
void Calculator::save_user_input(const std::string& input){
    if(is_input_correct(input)){
        user_input_ = input;
    }
    else {
        user_input_ = "";
       // exception here
    }
}
void Calculator::process_operands(const std::string& operand,
                                  std::vector<float>& operands) const {
  // TODO: probably rename to extract operands
  // TODO: use return value instead of output parameter
  float current_val = 0; // TODO: Do you need early initialization?
  current_val = std::stof(operand);
  operands.push_back(current_val);
}




float Calculator::process_operator(const std::string& operation,
                                   std::vector<float>& operands) const {
  // I suppose that operator may intract with more that 2 operants
  // I would say that it is overengineering for this task

  // Can we extract plus, minus , ... to separate functions?

  // ** Probably strategy pattern would better to be used instead of switch with inner calculations
//  float sum(std::vector<float>& operands){

//  }

  if ("+" == operation) {
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::plus<float>());
  }

  if ("-" == operation) {
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::minus<float>());
  }

  if ("*" == operation) {
    // Good place for switch
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::multiplies<float>());
  }

  if ("/" == operation) {
    if (std::any_of(operands.begin() + 1, operands.end(), compare(0))) {
      // ** This 'if' doesn't handle math operations itself. Probably should be moved to separate method
      // ** inside UI class to make input be checked before calculation
      // Looks like check devision by zero.
      // Result is 0 ? Any error handling ?
      return 0;
    }
    return std::accumulate(operands.cbegin() + 1,
                           operands.cend(),
                           operands[0],
                           std::divides<float>());
  }
  // This function is not error safe.
  // Please either make it error safe, or create assers in the begining
  return 0;
}

// **
bool Calculator::is_input_correct(const std::string &input)
{
    const std::regex input_pattern(
        R"(^(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s(-?\d*\.?\d*)\s*([\+\-\*\/])$)");
    const bool res = std::regex_search(input, sm_, input_pattern);
    return res;
}

bool Calculator::is_divident_equals_zero(std::string &operation)
{
    if("/" == operation){
        return true;
    }
    return false;
}

float Calculator::calculate_result() const {
  float final_res = 0;
  std::vector<float> operands;

  // auto will make it shorter
  for (std::smatch::iterator it = sm_.begin(); it != sm_.end(); ++it) {
    const bool is_num = is_number(*it);
    // *it value is not obvious, is it regexp search result? lexems?
    const bool is_operation = is_operator(*it);

    if (is_num) { // additional variables are redundant
      process_operands(*it, operands);
      // process funciton put *it in  operands if *it is operant
      //  I would give it another name
      continue;
    }

    if (is_operation) {
      final_res = process_operator(*it, operands);
      //  Reassigment final_res in loop is definitely bad idea
    }
  }
  return final_res;
}

}  // namespace dev
