// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<pair<int, int>> info(n);
		for (int i = 0; i < n; ++i) {
			cin >> info[i].first;
		}
		for (int i = 0; i < n; ++i) {
			cin >> info[i].second;
		}
		sort(info.rbegin(), info.rend());
		vector<int> f, s;
		for (int i = 0; i < n; ++i) {
			if (info[i].second == 1) {
				f.push_back(info[i].first);
			} else {
				s.push_back(info[i].first);
			}
		}
		int pf = 0, ps = 0, nf = (int) f.size(), ns = (int) s.size(); 
		while (m > 0 && (pf < nf || ps < ns)) {
			int sf = (pf < nf) ? f[pf] : 0, ss = (ps < ns) ? s[ps] : 0;
			if (sf >= m) {
				++ans;
				m = 0;
				break;
			}
			sf += (pf < nf - 1) ? f[pf + 1] : 0;
			if (sf >= m || ss >= m) {
				ans += 2;
				m = 0;
				break;
			}
			if (ss > sf) {
				++ps;
				ans += 2;
				m -= ss;
			} else {
				m -= f[pf];
				++ans;
				++pf;
			}
		}
		if (m > 0) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
	return 0;
}