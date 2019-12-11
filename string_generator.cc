#include "string_generator.h"

namespace dev {
    StringGenerator::StringGenerator(std::string basic)
        : _basic(basic) {}

    //TODO:
    // Use enum instead (will simplify usage outside):
    //  1) public method for convertion of char to enum value
    //  2) Move these constants to private
    const std::vector<char> StringGenerator::_operations = std::vector<char>{
            StringGenerator::cPlus,
            StringGenerator::cMinus,
            StringGenerator::cMult,
            StringGenerator::cDiv
        };

    bool StringGenerator::empty() {
        return 0 == _basic.length();
    }

    std::string StringGenerator::next() {
        std::string result = "";

        while(true) {
            if (_basic.empty()) {
                break;
            }
            auto item = _basic.front();
            _basic.erase(0,1);
            if (' ' == item) {
                break;
            }
            result+=item;
        }
        return result;
    }

    bool StringGenerator::isOperation(std::string item) {
        if (item.length() > 1) {
            return false;
        }

        const auto& front = item.front();

        // TODO:
        // _operations is redundant since there are const chars with operations within the same class
        for (const auto& op: _operations) {
            if (op == front) {
                return true;
            }
        }
        return false;
    }

    bool StringGenerator::isOperand(std::string item) {
        if (1 > item.length()) {
            return false;
        }

        // TODO:
        // I bet this part could be simplified...
        std::istringstream iss(item);
        float f;
        iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
        // Check the entire string was consumed and if either failbit or badbit is set
        return iss.eof() && !iss.fail();
    }
}
