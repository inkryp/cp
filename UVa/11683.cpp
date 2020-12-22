// https://onlinejudge.org/external/116/11683.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, c;
	while (cin >> a) {
		if (!a) {
			break;
		}
		cin >> c;
		int cur = a, ans = 0, tmp; // current height
		for (int i = 0; i < c; ++i) {
			cin >> tmp;
			if (cur > tmp) {
				ans += cur - tmp;
			}
			cur = tmp;
		}
		cout << ans << endl;
	}
	return 0;
}