#include "string"
#include "vector"
#include <sstream>

namespace dev {
class StringGenerator {
public:
    StringGenerator(const std::string& basic);
    bool next(std::string& result);
    bool empty();

    static bool isOperation(const std::string& item);
    static bool isOperand(const std::string& item);
    static bool getOperand(const std::string& item, float& result);

    static constexpr char cPlus = '+';
    static constexpr char cMinus = '-';
    static constexpr char cMult = '*';
    static constexpr char cDiv = '/';
private:
    std::string _basic;
};
}
