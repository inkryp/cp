// http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2661
#include <bits/stdc++.h>
using namespace std;

long long ans(const long long &n) {
	return ((1 + sqrt(1 + 4 * n * 2)) / 2) - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		cout << ans(n) << endl;
	}
	return 0;
}