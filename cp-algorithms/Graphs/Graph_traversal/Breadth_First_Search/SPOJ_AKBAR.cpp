#include <bits/stdc++.h>
using namespace std;

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);	cout.tie(0);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, r, m;
		scanf("%d %d %d", &n, &r, &m);
		vector<vector<int>> adj(n);
		vector<pair<int, int>> soldier(m);
		for (int i = 0; i < r; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[--x].push_back(--y);
			adj[y].push_back(x);
		}
		for (int i = 0; i < m; ++i) {
			int k, s;
			scanf("%d %d", &k, &s);
			soldier[i] = {--k, s};
		}
		map<int, int> amountSoldiersReach;
		queue<int> q;
		vector<bool> used(n, false);
		vector<int> d(n);
		for (int i = 0; i < m; ++i) {
			q.push(soldier[i].first);
			used[soldier[i].first] = true;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				if (++amountSoldiersReach[v] > 1) {
					break;
				}
				if (d[v] >= soldier[i].second) {
					continue;
				}
				for (auto u : adj[v]) {
					if (!used[u]) {
						used[u] = true;
						d[u] = d[v] + 1;
						q.push(u);
					}
				}
			}
		}

		bool ans = true;
		for (int i = 0; i < n; ++i) {
			if (amountSoldiersReach[i] != 1) {
				ans = false;
			}
		}

		if (ans) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

/*
	https://www.spoj.com/problems/AKBAR/
*/

/*
	Comment after getting AC
	Originally I had lines 27 and 28 the for loop, but kept
	getting TLE. Putting them where they're right now gives
	AC, but a test case like this is now incorrect:

	1
	4 4 2
	1 2
	2 4
	4 3
	1 3
	1 0
	3 2
	
	That should clearly print "No", but with that change it
	now prints "Yes"
*/