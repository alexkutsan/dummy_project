#pragma once
#include <exception>

struct InvalidOperandsException : public std::exception
{
  const char * what () const throw () {
    return "Invalid operands number";
  }
};

struct InvalidOpertionException : public std::exception
{
  const char * what () const throw () {
    return "Invalid operation";
  }
};
