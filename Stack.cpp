#include "Stack.h"
#include <iostream>

Stack::Stack(const std::vector<Token>& t) : size(0) /*: size(t.size()) */ //init vector
{
    //for(int i = size-1; i >= 0; --i) {
    for(int i = t.size()-1; i >= 0; --i) {
        push(t[i]);
    }
}

Stack::~Stack()
{
    size = 0;
    stk.clear();
}

int Stack::getSize() const
{
    return size;
}

void Stack::push(const Token& elem)
{
    if ( stk.size() <= size ) { // here size must be added after compate
        stk.push_back(elem);
        ++size;
    } else
        std::cout << "stack is full" << std::endl;
}

Token Stack::pop(int &rc)
{
    rc = 1;
    if ( stk.empty() ) {
        std::cout << "stack is empty" << std::endl;
        //return -EINVAL;
        rc = 0;
    } else {
        Token temp = stk.back();
        stk.pop_back();
        --size;
        return temp;
    }
}
