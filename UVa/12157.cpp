// https://onlinejudge.org/external/121/12157.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case " << tt << ": ";
		int n, tmp, mile = 0, juice = 0; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			mile += ((tmp / 30) + 1) * 10;
			juice += ((tmp / 60) + 1) * 15;
		}
		if (mile < juice) {
			cout << "Mile " << mile;
		} else if (mile == juice) {
			cout << "Mile Juice " << mile;
		} else {
			cout << "Juice " << juice;
		}
		cout << '\n';
	}
	return 0;
}