// https://onlinejudge.org/external/110/11078.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		int n, cur, cur_max, ans = INT_MIN;
		cin >> n >> cur_max; --n;
		while (n--) {
			cin >> cur;
			ans = max(ans, cur_max - cur);
			cur_max = max(cur_max, cur);
		}
		cout << ans << endl;
	}
	return 0;
}