#include "check_k.h"
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

bool check_k(string turn) {
	if (abs(turn[0] - turn[3]) > 1 || abs(turn[1] - turn[4]) > 1)return false;
	return true;
}