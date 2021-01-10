// https://onlinejudge.org/external/17/1721.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int xmax, ymax, num;
	string command;
	while (cin >> command) {
		if ('0' <= command[0] && command[0] <= '9') {
			xmax = stoi(command);
			cin >> ymax;
			num = 0;
		} else if (command == "OPEN") {

		} else if (command == "CLOSE") {

		} else if (command == "RESIZE") {

		} else { // command == "MOVE"
		
		}
		++num;
	}
	return 0;
}