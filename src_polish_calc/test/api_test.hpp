#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include "pc.hpp"


class api_test : public CppUnit::TestFixture {
private:
    pc::polish_calc calc;
    int N_NUMS = 500000;

public:

    void setUp() {}

    void tearDown() {}

    void test_api(){
        CPPUNIT_ASSERT(calc.num_elements() == 0);
        calc.add_num(5.556);
        calc.add_num(5.556);
        CPPUNIT_ASSERT(calc.num_elements() == 2);
        calc.clear_stack();
        CPPUNIT_ASSERT(calc.num_elements() == 0);
        
        // large volume addition test
        for(int i=0; i<N_NUMS; ++i) calc.add_num(1);
        for(int i=0; i<N_NUMS-1; ++i) calc.add_op('+');
        CPPUNIT_ASSERT(calc.num_elements() == 1);
        CPPUNIT_ASSERT(calc.get_result() == (double) N_NUMS);
    }

    static CppUnit::Test *suite(){
        CppUnit::TestSuite *ts = new CppUnit::TestSuite("add_*() API test");
        ts->addTest(new CppUnit::TestCaller<api_test>("test_api", &api_test::test_api));
        return ts;
    }

};

