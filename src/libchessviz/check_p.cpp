#include "check_p.h"
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

bool check_p(std::string turn) {
	if (turn[0] != turn[3] || abs(turn[4] - turn[1]) > 2 || abs(turn[4] - turn[1]) < 1) {
		return false;
	}
	return true;
}
