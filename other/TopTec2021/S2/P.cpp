// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, m, cur;
	long long ans = 0;
	cin >> n >> m;
	vector<int> c(n);
	for (auto &x : c) {
		cin >> x;
	}
	vector<vector<int>> adj(n);
	vector<bool> visited(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	function<void(int)> dfs = [&](int v) {
		visited[v] = true;
		for (int u : adj[v]) {
			if (!visited[u]) {
				cur = min(cur, c[u]);
				dfs(u);
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			cur = c[i];
			dfs(i);
			ans += cur;
		}
	}
	cout << ans << '\n';
	return 0;
}