#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <cmath>


namespace pc{
    union element;

    size_t              num_operands(char op);
    bool                eval_op(char op, std::stack<element>& opst);
    std::vector<double> _get_operands_from_stack(std::stack<element>& st, size_t n_ops);

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
        _num = std::numeric_limits<double>::quiet_NaN();
        ((char*)(&_op))[0] = op;
    }

    // initialize with a number
    element(double num){
        _num = num;
    }

    // check if union contains an operation
    bool is_op() const{
        return std::isnan(_num);
    }

    // returns the char of operation
    char get_op() const{
        if(!is_op()) std::runtime_error("Tried to get operation while the element holds a nummber");
        return ((char*)(&_op))[0];
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


// gets N_OPS elements from the top of ST (from oldest to newest)
std::vector<double> pc::_get_operands_from_stack(std::stack<element>& st, size_t n_ops){
    std::vector<double> ops;

    // check whether there are enough numbers in the stack
    if(st.size() < n_ops){
        std::runtime_error("Stack contains less numbers than needed");
        return ops;
    }

    for(size_t i=0; i<n_ops; ++i){
        ops.push_back(st.top()._num);
        st.pop();
    }

    // reverse the order so that the oldest element is first in the vector
    std::reverse(ops.begin(), ops.end());

    return ops;
}


// evaluates the operation modifying the stack as necessary (popping operands
// and pushing the result) and returns boolean indicating success
bool  pc::eval_op(char op, std::stack<element>& opst){
    auto oper = _n_operands.find(op);
    if( oper != _n_operands.end()){
        // op is a valid operation
        
        double res = 0;
        auto ops = _get_operands_from_stack(opst, num_operands(op));

        switch(oper->first){
            case '+':
            // addition
                res = ops[0] + ops[1];
                break;

            case '-':
            // subtraction
                res = ops[0] - ops[1];
                break;

            case '*':
            // multiplication
                res = ops[0] * ops[1];
                break;

            case '/':
            // division
                res = ops[0] / ops[1];
                break;

            case '^':
            // power
                res = std::pow(ops[0], ops[1]);
                break;

            case 'r':
            // sqrt
                res = std::sqrt(ops[0]);
                break;
        }

        opst.push(element(res));

        return true;
    }
    else{
        std::runtime_error("Unsupported operation character: " + std::to_string(op));
        return false;
    }
}


std::ostream& operator<<(std::ostream& os, const pc::element& el){
    if(el.is_op()) os << el.get_op();
    else os << el._num;
    
    return os;
}


#endif