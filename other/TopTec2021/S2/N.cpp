// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k, ans = 0, l = 0, a = 0, b = 0;
	string s, aux;
	cin >> n >> k >> s;
	for (int i = 0; i < n; ++i) {
		(s[i] == 'a') ? ++a : ++b;
		if (min(a, b) <= k) {
			ans = max(ans, a + b);
		} else {
			(s[l++] == 'a') ? --a : --b;
		}
	}
	cout << ans << '\n';
	return 0;
}