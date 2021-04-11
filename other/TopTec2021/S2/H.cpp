// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		cout << (((x & 1) == (y & 1) || x - 3 >= y) ? "YES" : "NO") << '\n';
	}
	return 0;
}