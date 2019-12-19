#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <vector>
#include "Token.h"

///TODO:namespace
class Stack {
    int size;
    std::vector<Token> stk;
public:
    ///TODO: stack is stack. do adapter for stack with Token
    Stack(const std::vector<Token>& t);
    ~Stack();
    void push(const Token& elem);
    Token pop(int &rc); ///TODO: think about another one interface
    int getSize() const;
};


#endif // STACK_H
