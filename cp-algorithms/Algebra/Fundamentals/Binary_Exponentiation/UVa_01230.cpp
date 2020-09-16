// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671
#include <bits/stdc++.h>
using namespace std;

long long binpow(long long x, long long y, long long n) {
	long long res = 1;
	while (y > 0) {
		if (y & 1) {
			res *= x;
			res = (res + n) % n;
		}
		x *= x;
		x = (x + n) % n;
		y >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long x, y, n; cin >> x >> y >> n;
		cout << binpow(x, y, n) << endl;
	}
	cin >> t;
	return 0;
}