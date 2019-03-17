#include <cppunit/ui/text/TestRunner.h>
#include "api_test.hpp"
#include "expr_test.hpp"

using namespace std;

int main(){
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(api_test::suite());
    runner.addTest(expr_test::suite());
    runner.run();
}