#include <iostream>
#include <string>
#include "pc.hpp"

using namespace std;
using namespace pc;

int main(){

    // === element test ===
    // element op('+');
    // element num(125.1024);

    // cout << "op: " << op.is_op() << " " << op << endl;
    // cout << "num: " << num.is_op() << " " << num << endl;


    string expr = "5.0 4.0 +  9  *1 - 80.000 / 3 + r 10 ^ 2 *";
    polish_calc calc;

    // should print 2048
    cout << expr << " => " << calc.eval_string(expr) << endl;

    return 0;
}