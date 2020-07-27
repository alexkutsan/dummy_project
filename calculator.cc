#include "operand.h"
#include "operator.h"
#include "calculator.h"
#include "calculator_exception.h"

#include <iterator>
#include <sstream>
#include <stack>

namespace dev {

std::vector<std::string> Calculator::parseTokens(const std::string& expression) const {
    std::istringstream iss(expression);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                     std::istream_iterator<std::string>());
    return tokens;  
}

double Calculator::calc(const std::string& expression) {
    std::vector<std::string> tokens = parseTokens(expression);
    std::stack<std::string> stkTokens;
    for (auto token : tokens) {
        if (Operator::isOperator(token)) {
            Operand operand1 = Operand(stkTokens.top());
            stkTokens.pop();
            Operand operand2 = Operand(stkTokens.top());
            stkTokens.pop();

            std::unique_ptr<Operator> operatr = OperatorFactory::getOperator(token);
            stkTokens.push(std::to_string(operatr->calculate(operand1, operand2)));
        } else {
            stkTokens.push(token);
        }
    }

    return std::stod(stkTokens.top());
}

}  // namespace dev
