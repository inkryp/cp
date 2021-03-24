// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n, all = 0; cin >> n;
		set<int> winners;
		vector< pair<long long, int> > a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			a[i].second = i + 1;
			all += a[i].first;
		}
		sort(a.rbegin(), a.rend());
		for (int i = 0; i < n; ++i) {
			long long cur = a[i].first;
			all -= cur;
			winners.insert(a[i].second);
			if (cur > all) {
				break;
			}
		}
		cout << (int) winners.size() << '\n';
		for (auto &ans : winners) {
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}