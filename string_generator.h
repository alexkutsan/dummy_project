#include "string"
#include "vector"
#include <sstream>

namespace dev {

class StringGenerator {
public:
    StringGenerator(std::string basic);
    std::string next();
    bool empty();

    static bool isOperation(std::string item);
    static bool isOperand(std::string item);

    static const char cPlus = '+';
    static const char cMinus = '-';
    static const char cMult = '*';
    static const char cDiv = '/';
private:
    std::string _basic;
    static const std::vector<char> _operations;
};
}
