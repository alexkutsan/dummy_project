#include "project.h"

namespace dev {

//TODO:
//  Think of alternative to exceptions

//TODO:
//  Use const string
float Project::run(std::string expression) {
    auto sGenerator = StringGenerator(expression);

    //TODO:
    //  Redundant check
    if (sGenerator.empty()){
        return 0;
    }

    float result = 0;

    auto stuff = [this](std::string operation) {
        //TODO:
        //  Get rid of hardcode
        if (2 != _queue.size()) {
            // UNDEFINED!!!
            throw std::exception();
        }

        //TODO:
        //  Looks like front() should be redefined in FixedQueue
        //  to perform front() and pop() within a single call
        float operand1 = _queue.front();
        _queue.pop();
        float operand2 = _queue.front();
        _queue.pop();

        //TODO:
        //  Use switch
        if (StringGenerator::cPlus == operation.front()) {
            return operand1 + operand2;
        } else if (StringGenerator::cMinus == operation.front()) {
            return operand1 - operand2;
        } else if (StringGenerator::cMult == operation.front()) {
            return operand1 * operand2;
        } else if (StringGenerator::cDiv == operation.front()) {
            return operand1 / operand2;
        } else {
            // UNREACHABLE!!!
            throw std::exception();
        }
    };

    while(true) {
        auto item = sGenerator.next();

        if (StringGenerator::isOperand(item)) {
            //TODO:
            //  Get rid of duplicated code (see string_generator.cc)
            std::istringstream iss(item);
            float fItem;
            iss >> std::noskipws >> fItem;
            _queue.push(fItem);

            continue;
        }

        if (StringGenerator::isOperation(item)) {
            float result = stuff(item);
            _queue.push(result);
            continue;
        }

        if (0 == item.length()) {
            break;
        }

        // UNREACHABLE!!!"
        throw std::exception();
    }

    if (!_queue.empty()) {
        result = _queue.front();
    }
    return result;
}
}  // namespace dev
