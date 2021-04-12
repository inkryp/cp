// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, tmp;
	long long ans = 0;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> tmp;
		x = abs(tmp);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == 0) {
			continue;
		}
		ans += (int)(upper_bound(a.begin(), a.end(), 2 * a[i]) - (a.begin() + i + 1));
	}
	cout << ans << '\n';
	return 0;
}