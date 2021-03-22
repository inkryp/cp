// 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, tmp; cin >> n;
		vector<int> amt(MAXN, 0), dp(MAXN, 0);
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			++amt[tmp];
		}
		for (int i = 1; i < MAXN; ++i) {
			dp[i] += amt[i];
			for (int j = 2 * i; j < MAXN; j += i) {
				dp[j] = max(dp[j], dp[i]);
			}
		}
		tmp = -1;
		for (int i = 1; i < MAXN; ++i) {
			tmp = max(tmp, dp[i]);
		}
		cout << n - tmp << '\n';
	}
	return 0;
}