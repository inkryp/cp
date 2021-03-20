// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, u, r, d, l;
		bool ans = false;
		cin >> n >> u >> r >> d >> l;
		for (int i = 0; i < (1 << 4); ++i) {
			// cout << i << endl;
			int tu = u, tr = r, td = d, tl = l;
			if (i & 1) {
				--tr;
				--tu;
			}
			if (i & 2) {
				--tu;
				--tl;
			}
			if (i & 4) {
				--tl;
				--td;
			}
			if (i & 8) {
				--td;
				--tr;
			}
			if (0 <= min(min(tu, tr), min(td, tl)) && max(max(tu, tr), max(td, tl)) <= n - 2) {
				ans = true;
				break;
			}
		}
		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}