// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, m, k, ans; cin >> n >> m >> k;
	vector<int> a(n), diff(n - 1);
	for (auto &x : a) {
		cin >> x;
	}
	for (int i = 0; i < n - 1; ++i) {
		diff[i] = a[i + 1] - a[i] - 1;
	}
	sort(diff.begin(), diff.end());
	ans = n;
	for (int i = 0; i < n - k; ++i) {
		ans += diff[i];
	}
	cout << ans << '\n';
	return 0;
}