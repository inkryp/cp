// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	vector<long long> c(n), a(n);
	vector<int> state(n, 0), path(n);
	vector<vector<long long>> adj(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		adj[i].push_back(--a[i]);
	}
	function<void(int)> dfs = [&] (int v) {
		state[v] = 1;
		for (int u : adj[v]) {
			if (!state[u]) {
				path[u] = v;
				dfs(u);
			} else if (state[u] == 1) {
				long long x = v, cur = c[v];
				while (x != u) {
					cur = min(cur, c[x]);
					x = path[x];
				}
				cur = min(cur, c[u]);
				ans += cur;
			}
		}
		state[v] = 2;
	};
	for (int i = 0; i < n; ++i) {
		if (!state[i]) {
			dfs(i);
		}
	}
	cout << ans << '\n';
	return 0;
}