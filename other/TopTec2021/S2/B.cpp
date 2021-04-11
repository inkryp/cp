// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, pos = 0, neg = 0, tmp, half; cin >> n;
	half = (n / 2) + bool(n & 1);
	while (n--) {
		cin >> tmp;
		if (tmp > 0) {
			++pos;
		} else if (tmp < 0) {
			++neg;
		}
	}
	if (pos >= half) {
		cout << 1 << '\n';
	} else if (neg >= half) {
		cout << -1 << '\n';
	} else {
		cout << 0 << '\n';
	}
	return 0;
}