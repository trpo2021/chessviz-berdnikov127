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

char** fill_desk(){
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

bool check_input(string turn) {
	if (turn[1] > '8' || turn[1] < '1' || turn[4]>'8' || turn[4] < '1') {
		return false;
	}
	if (turn[0] < 'a' || turn[0]>'h' || turn[3] < 'a' || turn[3]>'h') {
		return false;
	}
	return true;
}

bool check_p(string turn) {
	if (turn[0] != turn[3] || abs(turn[4] - turn[1]) > 2 || abs(turn[4] - turn[1]) < 1) {
		return false;
	}
	return true;
}
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
			for (int i;i <= j;i++) {
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
			for (int i; i<= j;i++) {
				if (arr[i][turn[0] - 96] != ' ') {
					return false;
				}
			}
		}
	}
	return true;
}

bool check_n(string turn) {
	int x = abs(turn[4] - turn[1]), y = abs(turn[0] - turn[3]);
	if ((x != 1 || y != 2) && (x != 2 || y != 1)) return false;
	return true;
}

bool check_b(char** arr, string turn) {
	if (abs(turn[4] - turn[1]) != abs(turn[3] - turn[0])) return false;
	if (turn[0] - 96 < turn[3] - 96 && 8 - turn[1] + 48 > 8 - turn[4] + 48 &&
		turn[0] - 96 > turn[3] - 96 && 8 - turn[1] + 48 < 8 - turn[4] + 48) {
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
		for (int i, j;j >= x;i++, j--) {
			cout << i<<' '<<j << endl;
			if (arr[i][j] != ' ') return false;
		}
	}
	else {
		int j = min(turn[0] - 96, turn[3] - 96);
		int i = min(8 - turn[1] + 48, 8 - turn[4] + 48);
		int x = max(turn[0] - 96, turn[3] - 96);
		if (8 - turn[1] + 48 == i&& turn[0] - 96 == j) {
			i++;
			j++;
		}
		else {
			x--;
		}
		for (int i, j;j <= x;i++, j++) {
			if (arr[i][j] != ' ') return false;
		}
	}
	return true;
}

bool check_k(string turn) {
	if (abs(turn[0] - turn[3]) > 1 || abs(turn[1] - turn[4]) > 1)return false;
	return true;
}

void print_desk(char** arr) {
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void do_turn(char** arr, string turn) {
	int i = 8 - turn[1] + 48;
	int j = turn[0] - 96;
	if (arr[i][j] == ' '||arr[8 - turn[4] + 48][turn[3] - 96]!=' ') {
		cout << "error"<<endl;
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
