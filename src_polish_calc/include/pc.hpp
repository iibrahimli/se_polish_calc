#ifndef PC_HPP
#define PC_HPP

#include <iostream>
#include <sstream>
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


    // just for convenience
    void add_op(char op){
        add_element(element(op));
    }


    // just for convenience
    void add_num(double num){
        add_element(element(num));
    }


    // evaluates a given expression string (MUST be space-separated) (ex: '2 4 + 5 *' will produce 30)
    double eval_string(std::string expr){
        std::istringstream in(expr);
        double tmp_num;
        char tmp_op;
        bool is_op = false;

        while(in){
            // ignore spaces
            if(in.peek() == ' '){
                in.ignore(1);
                continue;
            }
            else{
                // a digit means that we need to read a number
                if(std::isdigit(in.peek())){
                    in >> tmp_num;
                    is_op = false;
                }
                // read in a character
                else{
                    in >> tmp_op;
                    is_op = true;
                }

                // create and add element to stack
                if(is_op) add_element(element(tmp_op));
                else add_element(element(tmp_num));
            }
        }

        // expression done, but there are extra numbers left on the stack
        if(_opstack.size() > 1)
            std::cout << "Stack has more than one number left. Check the expression maybe" << std::endl;

        return _opstack.top()._num;
    }


private:
    std::stack<element> _opstack;      // operation stack

};


#endif