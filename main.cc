#include "project.h"

#include "executor.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std; // test

/*
 * The calculator input is double numbers, operators + - * /
 * The maximum input line is 255
 *
 * */

static int show_usage()
{
    std::cerr << "Usage: <option(s)> || <valid arguments>"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "Valid arguments:\n"
              << "\tSpecify target string after program name\n"
              << "\tNumbers with point and operations + - / * with space separation"
              << std::endl;
    return -1;
}

int main(int argc, char** argv) {

    try {
        if (argc < 2 /*|| argc >= 12*/) {
            show_usage();
            return 1;
        }

        std::vector <std::string> sources;
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if ((arg == "-h") || (arg == "--help")) {
                show_usage();
                return 0;
            } else {
                sources.push_back(arg);
            }
        }

        execute(sources);
    } catch (const std::invalid_argument& e) {
        std::cout << "std::invalid_argument" << std::endl;
        show_usage();
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range" << std::endl;
        show_usage();
    } catch (...) {
        /*
If no conversion could be performed, an invalid_argument exception is thrown.
If the value read is out of the range of representable values by a double (in some library implementations, this includes underflows), an out_of_range exception is thrown.
        */

        show_usage();
    }

    return 0;
}
