// https://onlinejudge.org/external/117/11764.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case " << tt << ": ";
		int n; cin >> n;
		vector<int> v(n);
		for (auto &x : v) {
			cin >> x;
		}
		int up = 0, down = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (v[i] < v[i + 1]) {
				++up;
			} else if (v[i] > v[i + 1]) {
				++down;
			}
		}
		cout << up << ' ' << down << endl;
	}
	return 0;
}