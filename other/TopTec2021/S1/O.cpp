// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ans = 1e9; cin >> n;
		vector<int> a(n), nums;
		map<int, int> c;
		for (auto &x : a) {
			cin >> x;
		}
		sort(a.begin(), a.end());
		nums.push_back(1);
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] != a[i]) {
				nums.push_back(1);
			} else {
				++nums.back();
			}
		}
		for (int i = 0; i < (int) nums.size(); ++i) {
			++c[nums[i]];
		}
		for (auto &[key, amt] : c) {
			int cur = key, tmp = 0;
			for (auto &[key, amt] : c) {
				if (cur <= key) {
					tmp += (key - cur) * amt;
				} else {
					tmp += key * amt;
				}
			}
			ans = min(ans, tmp);
		}
		cout << ans << '\n';
	}
	return 0;
}