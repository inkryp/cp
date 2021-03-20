// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long w, h, n; cin >> w >> h >> n;
		int twos = 0;
		while (w % 2 == 0) {
			++twos;
			w /= 2;
		}
		while (h % 2 == 0) {
			++twos;
			h /= 2;
		}
		// cout << "test: " << twos << endl;
		if (1LL << (twos) >= n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}