#ifndef PC_HPP
#define PC_HPP

#include <iostream>
#include <stack>
#include <cmath>
#include "element.hpp"


namespace pc{
    class polish_calc;
};


class pc::polish_calc{

    // adds an element to the stack and executes if element contains an operation
    void add_element(element el){
        if(el.is_op()){
            // element represents an operation
            
            // evaluates an operator on the given stack (modifies the stack)
            // the reason for this implementation is that the number of operands to an operator
            // is not fixed, and it is even possible to add support for operators accepting more
            // than 2 operands in future
            if(!eval_op(el.get_op(), _opstack))
                std::runtime_error("Error evaluating operation '" + std::to_string(el.get_op()) + "'");

        }
        else{
            // element is a number
            _opstack.push(el);
        }
    }


private:

    std::stack<element> _opstack;      // operation stack

};


#endif