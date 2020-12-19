// https://onlinejudge.org/external/116/11687.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	string s;
	while (cin >> s) {
		if (s == "END") {
			break;
		}
		if (s == "1") {
			cout << 1 << endl;
			continue;
		}
		int ans = 2, cur = s.size();
		while (cur != 1) {
			++ans;
			cur = ((cur == 0) ? 1 : (log10(cur) + 1));
		}
		cout << ans << endl;
	}
	return 0;
}