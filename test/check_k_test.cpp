#include <ctest.h>
#include <iostream>
#include <libchessviz/check_k.h>

CTEST(scan_suite, check_k)
{
	char inputtrue[]="e1-f2";
	char inputfalse[]="e1-f5";
	bool real=check_k(inputtrue);
    ASSERT_EQUAL(true, real);
    real=check_k(inputfalse);
    ASSERT_EQUAL(false, real);
}
