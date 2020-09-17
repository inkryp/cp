// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1587
#include <bits/stdc++.h>
using namespace std;

int valueOfCard(const char &c) {
	if ('2' <= c && c <= '9') {
		return c - '2' + 2;
	}
	return 10;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; ++t) {
		vector<string> cards(52 - 25);
		for (int i = 0; i < 52 - 25; ++i) {
			cin >> cards[i];
		}
		int y = 0;
		for (int i = 0; i < 3; ++i) {
			int x = valueOfCard(cards[cards.size() - 1][0]);
			y += x;
			cards.pop_back();
			for (int i = 0; i < 10 - x; ++i) {
				cards.pop_back();
			}
		}
		for (int i = 0; i < 25; ++i) {
			string x; cin >> x;
			cards.push_back(x);
		}
		cout << "Case " << t << ": " << cards[y - 1] << endl;
	}
	return 0;
}