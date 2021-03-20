// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, k; cin >> a >> b >> k;
		vector<pair<int, int>> couples(k);
		for (int i = 0; i < k; ++i) {
			cin >> couples[i].first;
		}
		for (int i = 0; i < k; ++i) {
			cin >> couples[i].second;
		}
		vector<int> boys(a, 0), girls(b, 0);
		for (auto &p : couples) {
			--p.first; --p.second;
			++boys[p.first];
			++girls[p.second];
		}
		long long ans = 0;
		for (auto &p : couples) {
			ans += k - (boys[p.first] + girls[p.second] - 1);
		}
		cout << ans / 2 << '\n';
	}
	return 0;
}