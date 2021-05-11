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
#include <libchessviz/fill_desk.h>
#include <libchessviz/check_input.h>
#include <libchessviz/print_desk.h>
#include <libchessviz/do_turn.h>

using namespace std;

int main() {
	char** desk = fill_desk();
	print_desk(desk);
	string turn;
	cout << "Enter move(for example a1-a2), enter 'exit' to exit\n";
	cin >> turn;
	while (turn != "exit") {
		if (!check_input(turn)) {
			cout << "error" << endl;
		}
		else {
			do_turn(desk, turn);
		}
		cout << endl << "--------------------" << endl;
		cin >> turn;
	}
}
