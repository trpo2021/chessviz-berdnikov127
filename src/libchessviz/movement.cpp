#include <libchessviz/output.h>
#include <iostream>
#include <stdio.h>
using namespace std;

char movement(char chessboard[11][11])
{
	char sline1, sline2, temp;
	int column1, column2, rline1, rline2, flag;

	cin >> sline1;
	cin >> column1;
	cin >> sline2;
	cin >> column2;
	flag = 0;
	if (sline1 == 'a')
		rline1 = 1;
	else if (sline1 == 'b')
		rline1 = 2;
	else if (sline1 == 'c')
		rline1 = 3;
	else if (sline1 == 'd')
		rline1 = 4;
	else if (sline1 == 'e')
		rline1 = 5;
	else if (sline1 == 'f')
		rline1 = 6;
	else if (sline1 == 'g')
		rline1 = 7;
	else if (sline1 == 'h')
		rline1 = 8;
	else
		flag = 1;

	if (sline2 == 'a')
		rline2 = 1;
	else if (sline2 == 'b')
		rline2 = 2;
	else if (sline2 == 'c')
		rline2 = 3;
	else if (sline2 == 'd')
		rline2 = 4;
	else if (sline2 == 'e')
		rline2 = 5;
	else if (sline2 == 'f')
		rline2 = 6;
	else if (sline2 == 'g')
		rline2 = 7;
	else if (sline2 == 'h')
		rline2 = 8;
	else
		flag = 1;

	if (column1 < 1 && column1 > 8)
		flag = 1;
		//trash = flag;
		

	if (column2 < 1 && column2 > 8)
		flag = 1;
		//trash = flag;
		

	if (flag == 0) {
		temp = chessboard[column1 - 1][rline1];
		chessboard[column1 - 1][rline1] = ' ';
		chessboard[column2 - 1][rline2] = temp;
		output(chessboard);
	}

	return chessboard[9][10];
}
