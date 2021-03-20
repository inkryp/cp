// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		bool ans = false;
		for (long long i = 0; i < 1e6 / 2020 + 10; ++i) {
			if (n > (2020 * i) && (n - 2020 * i) % 2021 == 0) {
				// cout << "here: " << abs(n - 2020 * i) << ' ' << i << endl;
				ans = true;
				break;
			}
		}
		for (long long i = 0; i < 1e6 / 2021 + 10; ++i) {
			if (n > (2021 * i) && (n - 2021 * i) % 2020 == 0) {
				// cout << "here: " << abs(n - 2020 * i) << ' ' << i << endl;
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