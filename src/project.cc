#include "project.h"
#include "string_generator.h"

namespace dev {

float Project::run(const std::string& expression) {
    auto stuff = [this](const std::string& operation, float& result) {
        float operand1;
        float operand2;

        if (!_queue.getFirst(operand1) ||
               ! _queue.getFirst(operand2)) {
            // UNDEFINED!!!
            throw std::runtime_error("Single operand! Undefined behaviour!");
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
            throw std::runtime_error("Undefined operation!");
        }
        return true;
    };

    auto sGenerator = StringGenerator(expression);
    float result = 0;
    std::string item;
    while(sGenerator.next(item)) {
        if (StringGenerator::isOperation(item)) {
            stuff(item, result);
            _queue.push(result);
            continue;
        }

        if (StringGenerator::getOperand(item, result)) {
            _queue.push(result);
            continue;
        }

        // UNREACHABLE!!!"
        throw std::runtime_error("Unreachable!");
    }


    _queue.getFirst(result);
    return result;
}
}  // namespace dev
