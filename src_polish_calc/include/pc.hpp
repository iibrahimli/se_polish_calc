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

public:

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
    double eval_string(const std::string& expr){
        std::istringstream in(expr);
        double tmp_num;
        char tmp_op;

        while(in){
            // ignore spaces
            if(std::isspace(in.peek()) || in.peek() == '\0'){
                in.ignore(1);
                continue;
            }
            else{
                // a digit means that we need to read a number
                if(std::isdigit(in.peek())){
                    if(!(in >> tmp_num)) break;
                    add_element(element(tmp_num));
                }
                // read in a character
                else{
                    if(!(in >> tmp_op)) break;
                    add_element(element(tmp_op));
                }
            }
        }

        // expression done, but there are extra numbers left on the stack
        if(_opstack.size() > 1)
            std::cout << "\nStack has " << _opstack.size() << " numbers left. Check the expression maybe" << std::endl;

        return _opstack.top()._num;
    }


    // result of operation (in "manual mode", i.e used with add_*())
    double get_result(){
        if(_opstack.size() != 1) return std::numeric_limits<double>::quiet_NaN();

        return _opstack.top()._num;
    }


    // returns number of elements on the stack
    size_t num_elements(){
        return _opstack.size();
    }


    // clears the contents of the stack
    void clear_stack(){
        while(!_opstack.empty()) _opstack.pop();
    }


private:
    std::stack<element> _opstack;      // operation stack

};


#endif