// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long a, b, k; cin >> a >> b >> k;
		long long aux = a - b, ans = 0;
		ans += aux * (k / 2);
		if (k & 1) {
			ans += a;
		}
		cout << ans << '\n';
	}
	return 0;
}