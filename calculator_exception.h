#pragma once

#include <exception>

class InvalidOperandException : public std::exception {
	const char * what () const throw () {
    	return "Invalid Operand Exception";
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
