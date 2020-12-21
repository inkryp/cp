// https://onlinejudge.org/external/116/11679.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int b, n;
	while (cin >> b >> n) {
		if (b == 0) {
			break;
		}
		vector<int> arr(b);
		for (auto &x : arr) {
			cin >> x;
		}
		int d, c, v;
		for (int i = 0; i < n; ++i) {
			cin >> d >> c >> v;
			arr[--d] -= v;
			arr[--c] += v;
		}
		bool s = true;
		for (auto &x : arr) {
			if (x < 0) {
				s = false;
				break;
			}
		}
		if (s) {
			cout << 'S' << endl;
		} else {
			cout << 'N' << endl;
		}
	}
	return 0;
}