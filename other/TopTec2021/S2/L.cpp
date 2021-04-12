// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k;
	string s;
	cin >> n >> k;
	vector<int> a(n), tmp;
	for (auto &x : a) {
		cin >> x;
	}
	auto solve = [&](vector<int> &tmp) {
		long long ans = 0;
		if (k >= (int) tmp.size()) {
			for (int i = 0; i < (int) tmp.size(); ++i) {
				ans += tmp[i];
			}
			return ans;
		}
		sort(tmp.rbegin(), tmp.rend());
		for (int i = 0; i < k; ++i) {
			ans += tmp[i];
		}
		return ans;
	};
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (tmp.empty()) {
			tmp.push_back(a[i]);
		}
		if (s[i] != s[i + 1]) {
			ans += solve(tmp);
			tmp.clear();
			tmp.push_back(a[i + 1]);
		} else {
			tmp.push_back(a[i + 1]);
		}
	}
	if (tmp.empty()) {
		tmp.push_back(a[n - 1]);
	}
	ans += solve(tmp);
	cout << ans << '\n';
	return 0;
}