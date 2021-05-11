#include "check_b.h"
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


bool check_b(char** arr, string turn) {
	if (abs(turn[4] - turn[1]) != abs(turn[3] - turn[0])) return false;
	if ((turn[0] - 96 < turn[3] - 96 && 8 - turn[1] + 48 > 8 - turn[4] + 48) ||(
		turn[0] - 96 > turn[3] - 96 && 8 - turn[1] + 48 < 8 - turn[4] + 48)) {
		int j = max(turn[0] - 96, turn[3] - 96);
		int i = min(8 - turn[1] + 48, 8 - turn[4] + 48);
		int x = min(turn[0] - 96, turn[3] - 96);
		if (8 - turn[1] + 48 == i && turn[0] - 96 == j) {
			i++;
			j--;
		}
		else {
			x++;
		}
		for (i=0, j=0;j >= x;i++, j--) {
			cout << i << ' ' << j << endl;
			if (arr[i][j] != ' ') return false;
		}
	}
	else {
		int j = min(turn[0] - 96, turn[3] - 96);
		int i = min(8 - turn[1] + 48, 8 - turn[4] + 48);
		int x = max(turn[0] - 96, turn[3] - 96);
		if (8 - turn[1] + 48 == i && turn[0] - 96 == j) {
			i++;
			j++;
		}
		else {
			x--;
		}
		for (i=0, j=0;j <= x;i++, j++) {
			if (arr[i][j] != ' ') return false;
		}
	}
	return true;
}


