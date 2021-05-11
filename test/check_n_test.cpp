#include <ctest.h>
#include <iostream>
#include <libchessviz/check_n.h>

CTEST(scan_suite, check_n)
{
	char inputtrue[]="b1-a3";
	char inputfalse[]="b1-b3";
	bool real=check_n(inputtrue);
    ASSERT_EQUAL(true, real);
    real=check_n(inputfalse);
    ASSERT_EQUAL(false, real);
}
