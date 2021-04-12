// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, x, y;
	string s;
	cin >> n >> s >> x >> y;
	const pair<int, int> final = {x, y};
	auto update = [&](pair<int, int> &pos, const char &c, const int &change) {
		if (c == 'U') {
			pos.second += change;
		} else if (c == 'D') {
			pos.second -= change;
		} else if (c == 'R') {
			pos.first += change;
		} else {
			pos.first -= change;
		}
	};
	auto possible = [&](const pair<int, int> pos, const int &cur) {
		int aux = (abs(pos.first - final.first) + abs(pos.second - final.second));
		return ((aux & 1) == (cur & 1)) && cur >= aux;
	};
	auto solve = [&](const int &cur) {
		pair<int, int> pos = {0, 0};
		// segment cant change
		for (int i = cur; i < n; ++i) {
			update(pos, s[i], 1);
		}
		int l = 0, r = cur;
		while (r != n) {
			if (possible(pos, cur)) {
				return true;
			}
			// now cant change
			update(pos, s[l++], 1);
			// now can change and revert before
			update(pos, s[r++], -1);
		}
		return possible(pos, cur);
	};
	if (!possible({0, 0}, n)) {
		cout << "-1\n";
		return 0;
	}
	int l = -1, r = n;
	while (r > l + 1) {
		int mid = (r + l) / 2;
		if (solve(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << '\n';
	return 0;
}