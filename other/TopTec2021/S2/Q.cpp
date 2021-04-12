// 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 10;
int dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, tmp;
	cin >> n;
	vector<int> c;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (c.empty() || tmp != c.back()) {
			c.push_back(tmp);
		}
	}
	n = (int) c.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (c[i] == c[n - j - 1]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	cout << n - (dp[n][n] + 1) / 2 << '\n';
	return 0;
}