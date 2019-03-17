#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include "pc.hpp"


class expr_test : public CppUnit::TestFixture {
private:
    pc::polish_calc calc;
    int N_NUMS = 10;

public:

    void setUp() {}

    void tearDown() {}

    void test_expr(){
        std::string expr = "5 4 + 6 - 2 ^ 2 ^ r 4 *";  // -> 36
        CPPUNIT_ASSERT_DOUBLES_EQUAL(calc.eval_string(expr), 36.0, 0.0001);
        calc.clear_stack();

        // big string test
        expr = "";
        for(int i=0; i<N_NUMS; ++i) expr += (std::string(" ") + std::to_string(1.0));
        for(int i=0; i<N_NUMS-1; ++i) expr += (std::string(" ") + "+");
        CPPUNIT_ASSERT_DOUBLES_EQUAL(N_NUMS, calc.eval_string(expr), 0.0001);
    }

    static CppUnit::Test *suite(){
        CppUnit::TestSuite *ts = new CppUnit::TestSuite("String expression evaluation test");
        ts->addTest(new CppUnit::TestCaller<expr_test>("test_expr", &expr_test::test_expr));
        return ts;
    }

};