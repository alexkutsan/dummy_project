#include "project.h"
#include "string"
#include "set"
#include "calc_exceptions.h"
#include <string>
#include <sstream>
#include <iterator>

namespace dev {

static const std::string plus = "+";
static const std::string minus = "-";
static const std::string multiply = "*";
static const std::string divide = "/";

std::vector<double> Project::process(const std::string &input)
{
    const std::vector<std::string> & args = parceInput(input);
    return processArguments(args);
}

std::vector<std::string> Project::parceInput(const std::string &input) {
    std::istringstream iss(input);
    std::vector<std::string> all_args(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());
    return all_args;
}

std::vector<double> Project::processArguments(const std::vector<std::string> &args)
{
    std::vector<double> operands;
    for (const auto & arg : args) {
        if (isOperator(arg)) {
            applyOperation(arg, operands);
        } else {
            operands.push_back(std::stod(arg));
        }
    }
    return operands;
}

bool Project::isOperator(const std::string &arg) const
{
    const std::set<std::string> operators{plus, minus, multiply, divide};
    return operators.find(arg) != operators.end();
}

void Project::applyOperation(const std::string &operation,
                             std::vector<double> &operands) const
{
    if (operands.size() > 1) {
        double result = 0;
        const double first_operand = operands[operands.size()-2];
        const double second_operand = operands[operands.size()-1];
        operands.erase(operands.end()-2, operands.end());
        if (operation == plus) {
            result = first_operand + second_operand;
        } else if (operation == minus ) {
            result = first_operand - second_operand;
        } else if (operation == multiply) {
            result = first_operand * second_operand;
        } else if (operation == divide ) {
            result = first_operand / second_operand;
        } else {
            throw InvalidOpertionException();
        }
        operands.push_back(result);
    } else {
        throw InvalidOperandsException();
    }
}

}  // namespace dev
