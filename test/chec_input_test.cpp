#include <ctest.h>
#include <iostream>
#include <libchessviz/check_input.h>

CTEST(scan_suite, check_input)
{
	char inputtrue[]="e2-e4";
	char inputfalse1[]="z2-e4";
	char inputfalse2[]="e0-e4";
	char inputfalse3[]="e2-j4";
	char inputfalse4[]="e2-e9";
    bool real=check_input(inputtrue);
    ASSERT_EQUAL(true, real);
    real=check_input(inputfalse1);
    ASSERT_EQUAL(false, real);
    real=check_input(inputfalse2);
    ASSERT_EQUAL(false, real);
    real=check_input(inputfalse3);
    ASSERT_EQUAL(false, real);
    real=check_input(inputfalse4);
    ASSERT_EQUAL(false, real);
}
