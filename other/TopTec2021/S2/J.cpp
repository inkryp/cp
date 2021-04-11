// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t;
	cin >> t;
	auto f = [&] (long long val) {
		return ((val & 1) ? -val : val);
	};
	while (t--) {
		long long l, r, ans;
		cin >> l >> r;
		ans = ((r - l + 1) / 2) * ((l & 1) ? 1 : -1);
		ans += ((r - l + 1) & 1) ? f(r) : 0;
		cout << ans << '\n';
	}
	return 0;
}