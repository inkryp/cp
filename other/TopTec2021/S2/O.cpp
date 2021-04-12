// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k, ans = 0, cnt = 0;
	string s;
	cin >> n >> k >> s;
	if (k == 2) {
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A' + (i & 1)) {
				++cnt;
			}
		}
		ans = (n < 2 * cnt) ? n - cnt : cnt;
		for (int i = 0; i < n; ++i) {
			s[i] = 'A' + (((cnt == ans) + i) & 1);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (s[i] == s[i + 1]) {
				++ans;
				char cur = 'A';
				while (cur == s[i] || cur == s[i + 2]) {
					++cur;
				}
				s[i + 1] = cur;
			}
		}
	}
	cout << ans << '\n' << s << '\n';
	return 0;
}