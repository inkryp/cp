// https://onlinejudge.org/external/115/11559.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		int cost = INT_MAX;
		for (int i = 0; i < h; ++i) {
			int price, available; cin >> price;
			for (int j = 0; j < w; ++j) {
				cin >> available;
				if (available >= n) {
					cost = min(cost, price * n);
				}
			}
		}
		if (cost <= b) {
			cout << cost << endl;
		} else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}