// 
#include <bits/stdc++.h>
using namespace std;

int MAXN = 1e4 + 10;
set<long long> cubes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	for (long long i = 1; i < MAXN; ++i) {
		cubes.insert(i * i * i);
	}

	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		bool ans = false;
		for (long long i = 1; i < MAXN; ++i) {
			if (cubes.count(x - i * i * i)) {
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