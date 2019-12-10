#include "project.h"
#include <iostream>
#include <sstream>

namespace dev {

float Project::run(std::string expression) {
    auto sGenerator = StringGenerator(expression);
    if (sGenerator.empty()){
        return 0;
    }

    float result = 0;

    auto stuff = [this](std::string operation) {
        std::cout << _queue.size() << "kek";
        if (2 != _queue.size()) {
            std::cout << "UNDEFINED!!!" << std::endl;
            throw;
        }

        float operand1 = _queue.front();
        _queue.pop();
        float operand2 = _queue.front();
        _queue.pop();

        if (StringGenerator::cPlus == operation.front()) {
            return operand1 + operand2;
        } else if (StringGenerator::cMinus == operation.front()) {
            return operand1 - operand2;
        } else if (StringGenerator::cMult == operation.front()) {
            return operand1 * operand2;
        } else if (StringGenerator::cDiv == operation.front()) {
            return operand1 / operand2;
        } else {
            std::cout << "UNREACHABLE!!!" << std::endl;
            throw;
        }
    };

    while(true) {
        auto item = sGenerator.next();

        if (StringGenerator::isOperand(item)) {
            std::istringstream iss(item);
            float fItem;
            iss >> std::noskipws >> fItem;
            _queue.push(fItem);

            continue;
        }

        if (StringGenerator::isOperation(item)) {
            stuff(item);
            continue;
        }

        if (0 == item.length()) {
            break;
        }

        std::cout << item << "UNREACHABLE KEK!!!" << std::endl;
        throw;
    }

    if (!_queue.empty()) {
        result = _queue.front();
    }
    return result;
}
}  // namespace dev
