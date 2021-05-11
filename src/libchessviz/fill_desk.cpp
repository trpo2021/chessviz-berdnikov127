#include "fill_desk.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <fstream>
#include <queue>
#include <sstream>
#include <cctype>

using namespace std;

char** fill_desk() {
	char** desk = new char* [9];
	string s = "RNBQKBNR";
	for (int i = 0;i < 9;i++) {
		desk[i] = new char[9];
		for (int j = 0;j < 9;j++) {
			if (i == 6 && j > 0) desk[i][j] = 'P';
			else if (i == 7 && j > 0) desk[i][j] = s[j - 1];
			else desk[i][j] = ' ';
		}
	}
	for (int i = 0;i < 8;i++) {
		desk[i][0] = 56 - i;
	}
	for (int i = 1;i < 9;i++) {
		desk[8][i] = 'a' + i - 1;
	}
	return desk;
}