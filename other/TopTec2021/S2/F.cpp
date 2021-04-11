// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k, l = 0, r = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] <= k) {
			++l;
		} else {
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] <= k) {
			++l;
		} else {
			break;
		}
	}
	cout << min(n, l + r) << '\n';
	return 0;
}