// https://onlinejudge.org/external/123/12372.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case " << tt << ": ";
		int l, w, h; cin >> l >> w >> h;
		if (l > 20 || w > 20 || h > 20) {
			cout << "bad" << endl;
		} else {
			cout << "good" << endl;
		}
	}
	return 0;
}