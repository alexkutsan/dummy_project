#include <assert.h>
#include <memory>
#include "polishcalc.h"
#include "polishcalcutils.h"
#include "operations.h"

namespace PolishCalcComponent {

value_t PolishCalc::calculate(const std::string &inputStr)
{
    std::vector<std::string> tokens;
    PolishCalcComponent::split2Tokens(inputStr, tokens);

    std::unique_ptr<IOperandsMemory> memory(makeMemory());

    processTokens(tokens, memory.get());

    assert(1 == memory->size());

    return memory->getOperand();
}

void PolishCalc::processTokens(const std::vector<std::string>& tokens, IOperandsMemory* memory)
{
    for (const auto& token: tokens) {
        operation_t operation = PolishCalcComponent::getOperation(token);
        memory->applyOperation(operation);
    }
}

}
