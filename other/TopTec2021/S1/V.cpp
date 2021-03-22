// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n, m, tmp, all; cin >> n >> m >> tmp;
		vector<long long> cur;
		map<long long, int> idx;
		cur.push_back(tmp);
		idx[tmp] = 0;
		all = tmp;
		for (int i = 1; i < n; ++i) {
			cin >> tmp;
			all += tmp;
			if (all > cur[(int) cur.size() - 1]) {
				cur.push_back(all);
				idx[cur[(int) cur.size() - 1]] = i;
			}
		}
		while (m--) {
			long long ans = (1LL << 60);
			cin >> tmp;
			if (cur[(int) cur.size() - 1] >= tmp || all > 0) {
				long long p = 0;
				if (cur[(int) cur.size() - 1] < tmp) {
					p = (tmp - cur[(int) cur.size() - 1] + all - 1) / all;
				}
				tmp -= p * all;
				ans = p * n + idx[*lower_bound(cur.begin(), cur.end(), tmp)];
			}
			cout << (ans < (1LL << 60) ? ans : -1) << ' ';
		}
		cout << '\n';
	}
	return 0;
}