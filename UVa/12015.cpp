// https://onlinejudge.org/external/120/12015.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cout << "Case #" << tc << ":\n";
		vector<pair<string, int>> arr(10);
		for (auto &p : arr) {
			cin >> p.first >> p.second;
		}
		int maxVal = INT_MIN;
		for (auto &p : arr) {
			maxVal = max(maxVal, p.second);
		}
		for (auto &p : arr) {
			if (p.second == maxVal) {
				cout << p.first << endl;
			}
		}
	}
	return 0;
}