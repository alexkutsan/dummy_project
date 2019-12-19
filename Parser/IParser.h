#ifndef PARSER_IPARSER_H
#define PARSER_IPARSER_H

#include <string>

namespace dev {

class IParser {
  public:
    virtual bool parse(const std::string& data) = 0;
};

}
#endif
