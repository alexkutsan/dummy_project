#pragma once
#include <string>

namespace dev{

class IProject {
    virtual double run(std::string) = 0;
};

}
