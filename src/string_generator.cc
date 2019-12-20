#include <vector>
#include <sstream>
#include "string_generator.h"

namespace dev {
    StringGenerator::StringGenerator(const std::string& basic)
        : _basic(basic) {}

    bool StringGenerator::empty() {
        return _basic.empty();
    }

    bool StringGenerator::next(std::string& result) {
        result = "";
        //not obvious loop!
        while(!empty()) {

            // get front and pop!!!
            auto item = _basic.front();
            _basic.erase(0,1);

            // how about const?
            if (' ' == item) {
                break;
            }
            result += item;
        }
        return !result.empty();
    }

    bool StringGenerator::isOperation(const std::string& item) {
        if (item.length() > 1) {
            return false;
        }

        const auto& front = item.front();

        switch (front) {
        case StringGenerator::cPlus:
        case StringGenerator::cMinus:
        case StringGenerator::cDiv:
        case StringGenerator::cMult:
            return true;
        default:
            return false;
        }
    }

    bool StringGenerator::isOperand(const std::string& item) {
        float result;
        return getOperand(item, result);
    }

    bool StringGenerator::getOperand(const std::string& item, float& result) {
        if (item.empty()) {
            return false;
        }

        // TODO:
        // I bet this part could be simplified...
        std::istringstream iss(item);
        iss >> std::noskipws >> result; // noskipws considers leading whitespace invalid
        // Check the entire string was consumed and if either failbit or badbit is set
        return iss.eof() && !iss.fail();
    }
}
