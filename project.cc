#include "project.h"

namespace dev {

//TODO:
//  Think of alternative to exceptions

float Project::run(const std::string& expression) {
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

    auto sGenerator = StringGenerator(expression);
    float result = 0;
    std::string item;
    while(sGenerator.next(item)) {
        if (StringGenerator::getOperand(item, result) ||
                (StringGenerator::isOperation(item) && stuff(item, result))) {
            _queue.push(result);
            continue;
        }

        // UNREACHABLE!!!"
        throw std::exception();
    }


    _queue.getFirst(result);
    return result;
}
}  // namespace dev
