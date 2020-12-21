// https://onlinejudge.org/external/126/12658.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n; cin >> n;
	string ans, s;
	for (int i = 0; i < 5; ++i) {
		cin >> s;
		if (i == 3) {
			for (int end = 3; end < 4 * n; end += 4) {
				string num = string(s.begin() + end - 3, s.begin() + end);
				if (num == ".*.") {
					ans += "1";
				} else if (num == "*..") {
					ans += "2";
				} else {
					ans += "3";
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}