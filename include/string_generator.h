#include "istring_generator.h"

namespace dev {
class StringGenerator : public IStringGenerator{
public:
    StringGenerator(const std::string& basic);
    bool next(std::string& result) override;
    bool empty() override;

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
