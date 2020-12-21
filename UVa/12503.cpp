// https://onlinejudge.org/external/125/12503.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ans = 0; cin >> n;
		string s; getline(cin, s);
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			if (s[0] == 'L') {
				v[i] = -1;
			} else if (s[0] == 'R') {
				v[i] = 1;
			} else {
				int val = stoi(string(s.begin() + 7, s.end()));
				v[i] = v[--val];
			}
			ans += v[i];
		}
		cout << ans << endl;
	}
	return 0;
}