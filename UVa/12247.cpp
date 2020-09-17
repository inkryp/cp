// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3399
#include <bits/stdc++.h>
using namespace std;

bool scanAll(vector<int> &v) {
	for (int &x : v) {
		cin >> x;
	}
	return true;
}

bool allZeros(const vector<int> &v) {
	for (auto &x : v) {
		if (x != 0) {
			return false;
		}
	}
	return true;
}

bool twoAlwaysLoose(const vector<int> &cards) {
	return cards[1] < cards[3];
}

bool twoAlwaysWin(const vector<int> &cards) {
	return cards[4] > cards[2];
}

bool canAlwaysWin(vector<int> cards, const int &x) {
	cards.push_back(x);
	sort(cards.begin() + 3, cards.end());
	if (twoAlwaysLoose(cards) || twoAlwaysWin(cards)) {
		return true;
	}
	return false;
}

bool cardNotInCards(const vector<int> &v, const int &num) {
	for (auto &x : v) {
		if (num == x) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	vector<int> cards(5);
	int i = 0;
	while (scanAll(cards) && !allZeros(cards)) {
		// Either
		// Princess has to have two that always looses
		// or King have two that always wins
		sort(cards.begin(), cards.begin() + 3);
		sort(cards.begin() + 3, cards.end());
		int ans = 53;
		for (int i = 52; i >= 1; --i) {
			if (canAlwaysWin(cards, i) && cardNotInCards(cards, i)) {
				ans = min(ans, i);
			}
		}
		if (ans > 52) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}