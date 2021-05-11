#include "print_desk.h"
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

void print_desk(char** arr) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}