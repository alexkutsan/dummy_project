#include "project.h"

namespace dev {

//TODO:
//  Think of alternative to exceptions

float Project::run(const std::string& expression) {
    auto sGenerator = StringGenerator(expression);

    auto stuff = [this](std::string operation, float& result) {
        float operand1;
        float operand2;

        if (!_queue.getFirst(operand1) ||
               ! _queue.getFirst(operand2)) {
            // UNDEFINED!!!
            return false;
        }

        const char& cOperation = operation.front();
        switch (cOperation) {
        case StringGenerator::cPlus:
            result = operand1 + operand2;
            break;
        case StringGenerator::cMinus:
            result = operand1 - operand2;
            break;
        case StringGenerator::cMult:
            result = operand1 * operand2;
            break;
        case StringGenerator::cDiv:
            result = operand1 / operand2;
            break;
        default:
            // UNREACHABLE!!!
            return false;
        }
        return true;
    };

    std::string item;
    while(true) {
        if (!sGenerator.next(item)) {
            break;
        }

        float operation_result = 0;
        if (StringGenerator::getOperand(item, operation_result) ||
                (StringGenerator::isOperation(item) && stuff(item, operation_result))) {
            _queue.push(operation_result);
            continue;
        }

        // UNREACHABLE!!!"
        throw std::exception();
    }

    float result = 0;
    _queue.getFirst(result);

    return result;
}
}  // namespace dev
