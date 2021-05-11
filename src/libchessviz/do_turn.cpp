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
#include <libchessviz/print_desk.h>
#include <libchessviz/fill_desk.h>
#include <libchessviz/check_input.h>
#include <libchessviz/print_desk.h>
#include <libchessviz/do_turn.h>
#include <libchessviz/check_p.h>
#include <libchessviz/check_r.h>
#include <libchessviz/check_n.h>
#include <libchessviz/check_b.h>
#include <libchessviz/check_k.h>

using namespace std;


void do_turn(char** arr, string turn) {
	int i = 8 - turn[1] + 48;
	int j = turn[0] - 96;
	if (arr[i][j] == ' ' || arr[8 - turn[4] + 48][turn[3] - 96] != ' ') {
		cout << "error" << endl;
		return;
	}
	if (arr[i][j] == 'P' && !check_p(turn)) cout << "error" << endl;
	else if (arr[i][j] == 'R' && !check_r(arr, turn)) cout << "error" << endl;
	else if (arr[i][j] == 'N' && !check_n(turn)) cout << "error" << endl;
	else if (arr[i][j] == 'B' && !check_b(arr, turn)) cout << "error" << endl;
	else if (arr[i][j] == 'Q' && !check_r(arr, turn) && !check_b(arr, turn)) cout << "error" << endl;
	else if (arr[i][j] == 'K' && !check_k(turn)) cout << "error" << endl;
	else {
		char c = arr[8 - turn[1] + 48][turn[0] - 96];
		arr[8 - turn[1] + 48][turn[0] - 96] = ' ';
		arr[8 - turn[4] + 48][turn[3] - 96] = c;
		print_desk(arr);
	}
}
