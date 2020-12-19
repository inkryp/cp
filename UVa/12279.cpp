// https://onlinejudge.org/external/122/12279.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t = 0, n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << "Case " << ++t << ": ";
		int ans = 0, tmp;
		while (n--) {
			cin >> tmp;
			if (tmp) {
				++ans;
			} else {
				--ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}