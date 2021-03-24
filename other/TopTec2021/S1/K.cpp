// 
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &box, vector<int> &spc) {
	if (box.empty() || spc.empty()) {
		return 0;
	}
	int ans = 0, m = (int) spc.size();
	vector<int> match(m + 1);
	for (int i = m - 1; i >= 0; --i) {
		match[i] = match[i + 1] + binary_search(box.begin(), box.end(), spc[i]);
	}
	for (int i = 0; i < m; ++i) {
		int move = (int) (upper_bound(box.begin(), box.end(), spc[i]) - box.begin());
		int lost = (int) (upper_bound(spc.begin(), spc.end(), spc[i] - move) - spc.begin());
		ans = max(ans, i - lost + 1 + match[i + 1]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, tmp; cin >> n >> m;
		vector<int> boxneg, boxpos, spcneg, spcpos;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			if (tmp < 0) {
				boxneg.push_back(-tmp);
			} else {
				boxpos.push_back(tmp);
			}
		}
		for (int i = 0; i < m; ++i) {
			cin >> tmp;
			if (tmp < 0) {
				spcneg.push_back(-tmp);
			} else {
				spcpos.push_back(tmp);
			}
		}
		reverse(boxneg.begin(), boxneg.end());
		reverse(spcneg.begin(), spcneg.end());
		cout << solve(boxneg, spcneg) + solve(boxpos, spcpos) << '\n';
	}
	return 0;
}