#include "check_r.h"
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


bool check_r(char** arr, string turn) {
	if (turn[0] != turn[3] && turn[1] != turn[4]) {
		return false;
	}
	else {
		bool f = (8 - turn[1] + 48 == 8 - turn[4] + 48) ? true : false;
		if (f) {
			int i = min(turn[0] - 96, turn[3] - 96);
			int j = max(turn[0] - 96, turn[3] - 96);
			if (turn[0] - 96 == i) i++;
			if (turn[0] - 96 == j) j--;
			for (i=0;i <= j;i++) {
				if (arr[8 - turn[1] + 48][i] != ' ') {
					return false;
				}
			}
		}
		else {
			int i = min(8 - turn[1] + 48, 8 - turn[4] + 48);
			int j = max(8 - turn[1] + 48, 8 - turn[4] + 48);
			if (8 - turn[1] + 48 == i) i++;
			if (8 - turn[1] + 48 == j) j--;
			for (i=0; i <= j;i++) {
				if (arr[i][turn[0] - 96] != ' ') {
					return false;
				}
			}
		}
	}
	return true;
}
