#pragma once

#include "operand.h"

#include <map>
#include <memory>
#include <functional>

namespace dev {

using Calculate = std::function<double(const Operand& operand1, const Operand& operand2)>;
using OperatorMap = std::map<char, Calculate>;

class Operator {
public:
    Operator(const Calculate& calculate);
    Calculate calculate;
};

class OperatorFactory {
public:
    static std::unique_ptr<Operator> getOperator(const std::string& token);
private:
    static OperatorMap operators_;
};

}  // namespace dev
