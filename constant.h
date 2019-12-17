#ifndef CONSTANT
#define CONSTANT

#include <limits>
#include <stack>

namespace polish_notation_constant
{
    typedef double value_t;
    typedef std::stack<value_t> stack_numbers_t;

    constexpr double ERROR_VALUE = std::numeric_limits<value_t>::max();

    enum class error_code {
        STACK_EMPTY,
        NOT_CORRECT_EXPRESSION,
        ZERO_DEVISION,
        NO_ERROR,
        NOT_CORRECT_COUNT_OF_OPERATION
    };
}

#endif // CONSTANT

