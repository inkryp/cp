// https://onlinejudge.org/external/15/1585.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int ans = 0, cur = 1;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == 'O') {
				ans += cur;
				++cur;
			} else {
				cur = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}