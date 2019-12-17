#include "polishcalc.h"
#include "polishcalcparser.h"

namespace PolishCalcComponent {

enum class Operations: char{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/'
};

CalcError PolishCalc::process(const std::string &str, value_t &res)
{
    std::vector<std::string> strs;

    if (ParseError::NO_ERROR != PolishCalcComponent::parseString(str, strs)){
        return CalcError::PARSE_ERROR;
    }


    CalcError error = processOperations(strs);
    if (CalcError::NO_ERROR != error){
        return error;
    }

    value_t result;
    if (LogicError::NO_ERROR !=m_logic.getResult(result)){
        return CalcError::LOGIC_ERROR;
    }

    res = result;
    return CalcError::NO_ERROR;
}

value_t add(const value_t& a, const value_t& b){
    return a + b;
}

value_t sub(const value_t& a, const value_t& b){
    return a - b;
}

value_t mul(const value_t& a, const value_t& b){
    return a * b;
}

value_t div(const value_t& a, const value_t& b){
    return a / b;
}

operation_t *PolishCalc::getOperation(const std::string &opStr)
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

CalcError PolishCalc::processOperations(const std::vector<std::string>& operations)
{

    for (auto& opStr: operations) {
        operation_t* op;

        op = getOperation(opStr);

        if (op){
            if(LogicError::NO_ERROR != m_logic.process(*op)){
                return CalcError::LOGIC_ERROR;
            }
        }
        else {
            std::string::size_type sz;
            value_t value = std::stod(opStr, &sz);

            if (sz == opStr.size()){
                if(LogicError::NO_ERROR != m_logic.addValue(value)){
                    return CalcError::LOGIC_ERROR;
                }
            }else {
                return CalcError::PROCESS_ERROR;
            }
        }

    }

    return CalcError::NO_ERROR;
}


}
