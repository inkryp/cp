// https://onlinejudge.org/external/131/13145.pdf
#include <bits/stdc++.h>
using namespace std;

const int md = 'z' - 'a' + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int t;
	while (cin >> t) {
		if (t == 0) {
			break;
		}
		while (t < 0) {
			t += md;
		}
		t %= md;
		string s;
		getline(cin, s);
		getline(cin, s);
		for (auto &c : s) {
			if ('a' <= c && c <= 'z') {
				int val = (c - 'a') + t;
				val %= md;
				c = val + 'a';
			} else if ('A' <= c && c <= 'Z') {
				int val = (c - 'A') + t;
				val %= md;
				c = val + 'A';
			}
		}
		cout << s << '\n';
	}
	return 0;
}