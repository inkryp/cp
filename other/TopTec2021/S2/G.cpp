// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k, tmp;
	cin >> n >> k;
	set<int> ans, val;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (val.count(tmp) == 0) {
			val.insert(tmp);
			ans.insert(i + 1);
		}
	}
	if ((int) ans.size() >= k) {
		cout << "YES\n";
		int i = 0;
		for (auto &x : ans) {
			cout << x << ' ';
			if (++i >= k) {
				break;
			}
		}
		cout << '\n';
	} else {
		cout << "NO\n";
	}
	return 0;
}