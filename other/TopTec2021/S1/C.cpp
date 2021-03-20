// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ans = 0; cin >> n;
		vector<int> v(n);
		for (auto &x : v) {
			cin >> x;
		}
		for (int i = 0; i < n - 1; ++i) {
			double tmp = (double) max(v[i], v[i + 1]) / min(v[i], v[i + 1]);
			if (tmp == (int) tmp && __builtin_popcount(tmp) == 1 && tmp != 1.0) {
				// cout << "tmp: " << tmp << '\t';
				--tmp;
			}
			ans += log2(tmp);
		}
		cout << ans << '\n';
	}
	return 0;
}