#ifndef POLISHCALCPARSER_H
#define POLISHCALCPARSER_H

#include<string>
#include<vector>

namespace PolishCalcComponent {

   enum class ParseError{
       NO_ERROR,
       EMPTY_INPUT
   };

   ParseError parseString(const std::string& str, std::vector<std::string>& strs);

}

#endif // POLISHCALCPARSER_H
