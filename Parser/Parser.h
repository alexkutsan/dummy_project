#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "IParser.h"
#include "CustomStack.h"
#include "utils.h"

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

      types::NumbersStackPtr get_numbers();
      types::OperatorsListPtr get_operators();

    private:
      std::string 
        string_matches_operator(const std::string& possible_operator) const; 
      std::vector<std::string> 
        split(const std::string&) const;
      types::NumbersStackPtr numbers_;
      types::OperatorsListPtr operators_;
  };
}

#endif
