#include "check_n.h"
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

bool check_n(string turn) {
	int x = abs(turn[4] - turn[1]), y = abs(turn[0] - turn[3]);
	if ((x != 1 || y != 2) && (x != 2 || y != 1)) return false;
	return true;
}
