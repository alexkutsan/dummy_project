#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace TOper {

///TODO: rename
///TODO: enum class
enum Operand {
    ADD,
    SUB,
    DIV,
    MUL,
    NONE
};

}

class Token
{
public:
    ///TODO: split to different constructors
    Token(const bool is_number, const TOper::Operand opr, const long double num);
    Token(const long double num);
    Token(const TOper::Operand opr);
    bool is_number();
    TOper::Operand getOperand();
    long double getNumber();
private:
    long double d;
    TOper::Operand opr;
    bool is_num;
};

#endif // TOKEN_H
