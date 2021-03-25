// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ans = 1e9; cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		sort(s.rbegin(), s.rend());
		for (int i = 0; i < n - 1; ++i) {
			ans = min(ans, s[i] - s[i + 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}