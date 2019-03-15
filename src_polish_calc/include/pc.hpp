#ifndef PC_HPP
#define PC_HPP

#include <stack>
#include <cmath>
#include "element.hpp"


namespace pc{
    class polish_calc;
};


class polish_calc{

    polish_calc() = default;

private:
    std::stack<element> opstack;


};


#endif