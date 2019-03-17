#include <iostream>
#include <string>
#include "pc.hpp"

using namespace std;
using namespace pc;

int main(int argc, const char *argv[]){

    if(argc != 2){
        cout << "No single expression provided" << endl; 
        return 1;
    }

    polish_calc calc;
    string expr = argv[1];

    cout << calc.eval_string(expr) << endl;

    return 0;
}