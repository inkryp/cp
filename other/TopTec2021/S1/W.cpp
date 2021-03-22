// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector< vector<bool> > a(n, vector<bool>(n)), b(n, vector<bool>(n));
		string s; bool ans = true;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < n; ++j) {
				a[i][j] = s[j] - '0';
			}
		}
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < n; ++j) {
				b[i][j] = s[j] - '0';
			}
		}
		for (int j = 0; j < n; ++j) {
			if (a[0][j] != b[0][j]) {
				for (int i = 0; i < n; ++i) {
					a[i][j] = !a[i][j];
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			bool flip = (a[i][0] ^ b[i][0]);
			for (int j = 1; j < n; ++j) {
				if (flip != (a[i][j] ^ b[i][j])) {
					ans = false;
					break;
				}
			}
		}
		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
	return 0;
}