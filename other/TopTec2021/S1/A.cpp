// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<string> check(8, string((int) s.size(), 'a'));
		for (int cases = 0; cases < (int) check.size(); ++cases) {
			for (int i = 0; i < (int) s.size(); ++i) {
				if (s[i] == 'A') {
					if (cases & 4) {
						check[cases][i] = '(';
					} else {
						check[cases][i] = ')';
					}
				} else if (s[i] == 'B') {
					if (cases & 2) {
						check[cases][i] = '(';
					} else {
						check[cases][i] = ')';
					}
				} else {
					if (cases & 1) {
						check[cases][i] = '(';
					} else {
						check[cases][i] = ')';
					}
				}
			}
		}
		bool ans = false;
		for (auto &x : check) {
			// cout << "Test: " << x << endl;
			stack<bool> elems;
			bool out = false;
			for (int i = 0; i < (int) x.size(); ++i) {
				if (x[i] == '(') {
					elems.push(true);
				} else {
					if (elems.empty()) {
						out = true;
						break;
					} else {
						elems.pop();
					}
				}
			}
			if (elems.empty() && !out) {
				ans = true;
				break;
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