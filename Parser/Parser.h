#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "IParser.h"
#include "CustomStack.h"

#include <vector>
#include <memory>
#include <string>
#include <limits>
#include <iostream>
#include <sstream>
#include <exception>

namespace dev {

  using namespace types;

  class Parser : public IParser {
    public:
      Parser();
      bool parse(const std::string& data) override;

      NumbersStackPtr get_numbers();
      OperatorsListPtr get_operators();

    private:
      std::string string_matches_operator(const std::string& possible_operator); 
      NumbersStackPtr numbers_;
      OperatorsListPtr operators_;
  };
}

#endif
