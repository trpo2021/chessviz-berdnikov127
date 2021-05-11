#include <ctest.h>
#include <iostream>
#include <libchessviz/check_p.h>

CTEST(scan_suite, check_p)
{
	char inputtrue[]="e2-e3";
	char inputfalse[]="e2-b4";
	bool real=check_p(inputtrue);
    ASSERT_EQUAL(true, real);
    real=check_p(inputfalse);
    ASSERT_EQUAL(false, real);
}
