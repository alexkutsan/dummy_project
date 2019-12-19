#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include <vector>

class Parser
{
public:
    Parser(const std::vector <std::string>& line);
    void parse();
    const std::vector<Token>& getTokens();
    size_t getPositionOfErrorInRawLine() const;
private:
    std::vector<Token> tokens;
    std::vector <std::string> rawLines;
    size_t currentPosition;
};

#endif // PARSER_H
