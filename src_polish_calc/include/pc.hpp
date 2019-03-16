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
            if(_opstack.size() >= num_operands(el.get_op()))
                element op2 = _opstack.top();
                _opstack.pop();
                element op1 = _opstack.top();
                _opstack.push(op2);

                _opstack.push(eval_op(el.get_op(), op1, op2));
            else{
                std::runtime_error("Stack contains less elements than needed for the operation");
            }
        }
        else{
            // element is a number
            _opstack.push(el);
        }
    }


private:

    std::stack<element> _opstack;  // operation stack

};


#endif