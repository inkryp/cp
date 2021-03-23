// 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 10;
int n, d[MAXN], a[MAXN];

void build(const int &l, const int &r, int depth) {
	if (l > r) {
		return;
	}
	if (l == r) {
		d[l] = depth;
		return;
	}
	int idx = l;
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] > a[idx]) {
			idx = i;
		}
	}
	d[idx] = depth;
	build(l, idx - 1, depth + 1);
	build(idx + 1, r, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		fill(d, d + n, 0);
		build(0, n - 1, 0);
		for (int i = 0; i < n; ++i) {
			cout << d[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}