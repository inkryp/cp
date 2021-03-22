// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, t; cin >> n >> t;
	map< pair<int, int>, char > edges;
	set< pair<int, int> > both, same;
	while (t--) {
		char op; cin >> op;
		if (op == '+') {
			int u, v; char c;
			cin >> u >> v >> c;
			edges[{u, v}] = c;
			if (edges.find({v, u}) != edges.end()) {
				both.insert({min(u, v), max(u, v)});
				if (edges[{v, u}] == c) {
					same.insert({min(u, v), max(u, v)});
				}
			}
		} else if (op == '-') {
			int u, v; cin >> u >> v;
			edges.erase({u, v});
			both.erase({min(u, v), max(u, v)});
			same.erase({min(u, v), max(u, v)});
		} else {
			int k; cin >> k;
			bool ans = ((k & 1) ? !both.empty() : !same.empty());
			cout << (ans ? "YES\n" : "NO\n");
		}
	}
	return 0;
}