#include "polishcalcparser.h"


PolishCalcComponent::ParseError PolishCalcComponent::parseString(const std::string &str, std::vector<std::string>& strs)
{
    strs.clear();

    if (str.size() == 0){
        return ParseError::EMPTY_INPUT;
    }

    size_t pos = str.find_first_of( ' ' );
    size_t initialPos = 0;

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( str.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = str.find_first_of( ' ', initialPos );
    }

    // Add the last one
    strs.push_back( str.substr( initialPos, std::min( pos, str.size() ) - initialPos + 1 ) );

    return ParseError::NO_ERROR;
}
