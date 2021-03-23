// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ans = 0; cin >> n;
		vector<int> a(n), dp(n);
		for (auto &x : a) {
			cin >> x;
		}
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = a[i];
			int next = a[i] + i;
			if (next < n) {
				dp[i] += dp[next];
			}
		}
		for (int i = 0; i < n; ++i) {
			ans = max(ans, dp[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}