// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector< pair<int, int> > blocks(m);
		for (auto &p : blocks) {
			cin >> p.second >> p.first;
		}
		sort(blocks.begin(), blocks.end());
		bool ans = (m % 2 == 0);
		for (int i = 0; i < m; i += 2) {
			// two consecutive same color or "forced" by "wall"
			if (((blocks[i].first + blocks[i].second) & 1) == ((blocks[i + 1].first + blocks[i + 1].second) & 1)
				|| ((i < m - 2) && (blocks[i + 1].first == blocks[i + 2].first))) {
				ans = false;
				break;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}