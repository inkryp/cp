// https://onlinejudge.org/external/117/11786.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		// track position of character '\'
		stack<int> pos;
		int ans = 0;
		for (int i = 0; i < (int) s.size(); ++i) {
			if (s[i] == '/' && !pos.empty()) {
				// cout << "\"" << i - pos.top() << "\"" << endl;
				ans += i - pos.top();
				pos.pop();
			} else if (s[i] == '\\') {
				pos.push(i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}