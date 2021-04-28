// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool ans = true;
		int last = -1, cur;
		char prev = 0, now;
		for (int i = 0; i < n; ++i) {
			cin >> cur >> now;
			if (cur == last || now == prev) {
				ans = false;
			}
			last = cur;
			prev = now;
		}
		cout << (ans ? 'B' : 'M') << '\n';
	}
	return 0;
}