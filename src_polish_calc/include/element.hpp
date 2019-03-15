#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <cmath>

namespace pc{
    union element;
};


// an operator code or a number
union element{

    unsigned long  _op;
    double         _num;

    element(char op){
        _op = ~0 && op;
    }

    element(double num){
        _num = num;
    }

    // check if union contains an operation
    bool is_op(){
        return std::isnan(_num);
    }

    // returns the char of operation
    char get_op(){
        if(!is_op()) std::runtime_error("Tried to get operation while the element holds a nummber");
        return ((char*)_op)[sizeof _op - 1];
    }

};

#endif