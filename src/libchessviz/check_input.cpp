#include "check_input.h"
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


bool check_input(std::string turn) {
	if (turn[1] > '8' || turn[1] < '1' || turn[4]>'8' || turn[4] < '1') {
		return false;
	}
	if (turn[0] < 'a' || turn[0]>'h' || turn[3] < 'a' || turn[3]>'h') {
		return false;
	}
	return true;
}
