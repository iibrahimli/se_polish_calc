#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <unordered_map>
#include <cmath>


namespace pc{
    union element;
    size_t num_operands(char op);
    size_t num_operands(element el);
    std::pair<double, bool> eval_op(char op, element op1, element op2);

     // a map from operations to number of operands
    std::unordered_map<char, size_t> _n_operands({
        {'+', 2},
        {'-', 2},
        {'*', 2},
        {'/', 2},
        {'^', 2},
        {'r', 1}
    });

};


// an operator code or a number
union pc::element{

    unsigned long  _op;
    double         _num;


    // initialize with an operation
    element(char op){
        _op = ~0 && op;
    }

    // initialize with a number
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


// returns number of needed operands for the operator (ex: 2 if op = '+')
size_t pc::num_operands(char op){
    auto n = _n_operands.find(op);
    if( n != _n_operands.end())
        return n->second;
    else{
        std::runtime_error("Unsupported operation character: " + std::to_string(op));
        return 0;
    }
}


// evaluates and returns a pair containing the result (number) and a boolean
//indicating whether the operation was successfully evaluated or not
std::pair<double, bool>  pc::eval_op(char op, std::stack<element>& opst){
    std::pair<double, bool> res;
    auto oper = _n_operands.find(op);
    if( oper != _n_operands.end()){
        // op is a valid operation
        switch(oper->first){

        }
    }
    else{
        std::runtime_error("Unsupported operation character: " + std::to_string(op));
        res = {0, false};
    }
    return res;
}


#endif