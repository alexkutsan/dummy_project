#include <string>
#include <assert.h>
#include "polishcalcutils.h"

//TODO: make it easier
void PolishCalcComponent::split2Tokens(const std::string& in, std::vector<std::string>& out)
{
    assert(in.size() != 0);

    out.clear();

    size_t pos = in.find_first_of( ' ' );
    size_t initialPos = 0;

    // Decompose statement
    while( pos != std::string::npos ) {
        out.push_back( in.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = in.find_first_of( ' ', initialPos );
    }

    // Add the last one
    out.push_back( in.substr( initialPos, std::min( pos, in.size() ) - initialPos + 1 ) );
}

namespace{

PolishCalcComponent::value_t add(const PolishCalcComponent::value_t& a, const PolishCalcComponent::value_t& b){
    return a + b;
}

PolishCalcComponent::value_t sub(const PolishCalcComponent::value_t& a, const PolishCalcComponent::value_t& b){
    return a - b;
}

PolishCalcComponent::value_t mul(const PolishCalcComponent::value_t& a, const PolishCalcComponent::value_t& b){
    return a * b;
}

PolishCalcComponent::value_t div(const PolishCalcComponent::value_t& a, const PolishCalcComponent::value_t& b){
    return a / b;
}

enum class Operations: char{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/'
};

}

PolishCalcComponent::operation_t *PolishCalcComponent::getOperation(const std::string &opStr)
{
    if (opStr.length() == 1){

        switch (static_cast<Operations>(opStr[0])) {
        case Operations::ADD:
            return &add;
        case Operations::SUB:
            return &sub;
        case Operations::MUL:
            return &mul;
        case Operations::DIV:
            return &div;
        default:
            return nullptr;
        }
    }

    return nullptr;
}

PolishCalcComponent::value_t PolishCalcComponent::getValue(const std::string &valStr)
{
    std::string::size_type sz;
    value_t value = std::stod(valStr, &sz);

    assert(sz == valStr.size());

    return value;
}
