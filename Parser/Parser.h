#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "IParser.h"

#include <vector>
#include <memory>
#include <string>
#include <limits>
#include <iostream>
#include <sstream>
#include <exception>

namespace dev {

  class Parser : public IParser {
    public:
      Parser();
      bool parse(const std::string& data) override;

      std::unique_ptr<std::vector<int>> get_numbers();
      std::unique_ptr<std::vector<std::string>> get_operators();

    private:
      std::string string_matches_operator(const std::string& possible_operator); 
      std::unique_ptr<std::vector<int>> numbers_;
      std::unique_ptr<std::vector<std::string>> operators_;
  };
}

#endif
