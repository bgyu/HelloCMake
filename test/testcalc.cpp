#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "TestCalc"

#include <boost/test/unit_test.hpp>
#include "calc.h"

BOOST_AUTO_TEST_SUITE(TestAdd)
    BOOST_AUTO_TEST_CASE(TestAdd1)
    {
        BOOST_TEST(calc::add(1, 2) == 3);
    }
    
    BOOST_AUTO_TEST_CASE(TestAdd2)
    {
        BOOST_TEST(calc::add(1, 0) == 1);
    }

    BOOST_AUTO_TEST_CASE(TestAdd3)
    {
        BOOST_TEST(calc::add(1, -1) == 0);
    }

BOOST_AUTO_TEST_SUITE_END()
