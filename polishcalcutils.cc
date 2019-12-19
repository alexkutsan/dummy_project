#include <string>
#include <assert.h>
#include "polishcalcutils.h"
#include "operandsmemory.h"

namespace PolishCalcComponent {


//TODO: make it easier
void split2Tokens(const std::string& in, std::vector<std::string>& out)
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

IOperandsMemory *makeMemory()
{
    return new OperandsMemory();
}

}
