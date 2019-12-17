#include "string"

#ifndef ISTRINGGENERATOR_H
#define ISTRINGGENERATOR_H

namespace dev {
class IStringGenerator {
public:
    virtual bool next(std::string& result) = 0;
    virtual bool empty() = 0;
};
}

#endif // ISTRINGGENERATOR_H

