#include <assert.h>
#include "polishcalc.h"
#include "polishcalcutils.h"

namespace PolishCalcComponent {

value_t PolishCalc::calculate(const std::string &inputStr)
{
    std::vector<std::string> tokens;
    PolishCalcComponent::split2Tokens(inputStr, tokens);

    processTokens(tokens);

    return m_logic.getResult();
}

void PolishCalc::processTokens(const std::vector<std::string>& tokens)
{
    m_logic.reset();

    for (const auto& token: tokens) {
        processToken(token);
    }
}

void PolishCalc::processToken(const std::string &token)
{
    operation_t* operationPtr;

    operationPtr = PolishCalcComponent::getOperation(token);

    if (operationPtr){
        m_logic.process(*operationPtr);
    }
    else {
        value_t value = PolishCalcComponent::getValue(token);
        m_logic.addValue(value);
    }
}


}
