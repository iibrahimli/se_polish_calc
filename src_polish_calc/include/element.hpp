#ifndef PC_HPP
#define PC_HPP

#include <cmath>

namespace pc{
    union element;
};


// an operator code or a number
union element{

    unsigned long  op;
    double         num;

    bool is_op(){
        return std::isnan(num);
    }

};

#endif