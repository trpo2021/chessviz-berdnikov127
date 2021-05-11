#include <ctest.h>
#include <iostream>
#include <libchessviz/fill_desk.h>

CTEST(scan_suite, fill_desk)
{
    char** realdesk = fill_desk();
    char expdesk[10][10]
    				= {"8        ",
               		   "7        ",
               		   "6        ",
               		   "5        ",
               		   "4        ",
               		   "3        ",
               		   "2PPPPPPPP",
               		   "1RNBQKBNR",
				   " abcdefgh"};
    for(int i=0;i<9;i++){
    	for(int z=0;z<9;z++)
    		ASSERT_EQUAL(expdesk[i][z], realdesk[i][z]);
	}
}
