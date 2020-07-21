#pragma once

#include <exception>

namespace dev {

class InvalidOperandException : public std::exception {
	const char * what () const throw () {
    	return "Invalid Operand Exception";
    }
};

class OperandOutOfRangeException : public std::exception {
	const char * what () const throw () {
    	return "Operand Out Of Range Exception";
    }
};

class InvalidOperatorException : public std::exception {
	const char * what () const throw () {
    	return "Invalid Operator Exception";
    }
};

class DivideByZeroException : public std::exception {
	const char * what () const throw () {
    	return "Divide By Zero Exception";
    }
};

}  // namespace dev
