// https://onlinejudge.org/external/117/11799.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case " << tt << ": ";
		int n, ans = INT_MIN; cin >> n;
		vector<int> v(n);
		for (auto &x : v) {
			cin >> x;
		}
		for (auto &x : v) {
			ans = max(ans, x);
		}
		cout << ans << endl;
	}
	return 0;
}