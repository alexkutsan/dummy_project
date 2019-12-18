#include "project.h"
#include "constant.h"
#include <iostream>
#include <string>

int main()
{
    dev::Project project;
    auto value = project.run("2 2 +");

    if( value != polish_notation_constant::ERROR_VALUE)
    {
       std::cout << "Result: " <<  value << std::endl;
    }
    else
    {
        std::cout << "Error code: " << project.get_error_code()  << std::endl;
    }

    return 0;
}
