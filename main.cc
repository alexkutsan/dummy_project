#include "project.h"
#include <iostream>

int main(int argc, char *argv[]) {
    //TODO:
    //  There should be easier way to convert CL args to a single string
    std::string args= "";
    for (int i = 1; i < argc; ++i) {
        args += argv[i];
        if (i != argc-1) {
            args += ' ';
        }
    }

    dev::Project project;
    float result = project.run(args);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
