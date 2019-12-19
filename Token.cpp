#include "Token.h"

Token::Token(const bool is_number, const TOper::Operand opr, const long double num)
    : is_num(is_number)
{
    if(is_num) {
        d = num;
        this->opr = TOper::NONE;
    } else {
        this->opr = opr;
        d = 0; //default
    }
}

Token::Token(const long double num)
    : is_num(true)
    , d(num)
    , opr(TOper::NONE)
{}

Token::Token(const TOper::Operand opr)
    : is_num(false)
    , d(0)
    , opr(opr)
{}

TOper::Operand Token::getOperand()
{
    return opr;
}

long double Token::getNumber()
{
    return d;
}

bool Token::is_number()
{
    return is_num;
}
