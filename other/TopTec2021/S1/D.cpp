// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, tgt, ans = 0; cin >> n;
		vector<pair<int, int>> md(3);
		for (int i = 0; i < n; ++i) {
			cin >> tgt;
			if (tgt % 3 == 0) {
				++md[0].first;
			} else if (tgt % 3 == 1) {
				++md[1].first;
			} else {
				++md[2].first;
			}
		}
		tgt = n / 3;
		md[0].second = 0;
		md[1].second = 1;
		md[2].second = 2;
		sort(md.begin(), md.end());
		auto getMd = [&] (int gtr, int lss) {
			int tmp = gtr - lss + 3;
			tmp %= 3;
			return 3 - tmp;
		};
		// cout << "pairs" << endl;
		// for (auto &p : md) {
		// 	cout << p.first << ' ' << p.second << endl;
		// }
		if (md[1].first < tgt) {
			// cout << "first" << endl;
			ans += (tgt - md[1].first) * getMd(md[2].second, md[1].second);
			ans += (tgt - md[0].first) * getMd(md[2].second, md[0].second);
		} else if (md[1].first == tgt) {
			// cout << "second" << endl;
			ans += (tgt - md[0].first) * getMd(md[2].second, md[0].second);
		} else {
			// cout << "third" << endl;
			ans += (md[1].first - tgt) * getMd(md[1].second, md[0].second);
			ans += (md[2].first - tgt) * getMd(md[2].second, md[0].second);
		}
		cout << ans << '\n';
	}
	return 0;
}