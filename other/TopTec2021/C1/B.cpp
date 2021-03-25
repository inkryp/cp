// 
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int n;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		long long m, x, y;
		bool ans = true;
		cin >> m;
		vector< vector<long long> > adj(n);
		vector<long long> color(n, -1);
		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		queue<long long> q;
		for(int i = 0; i < n; ++i) {
			if(color[i] == -1) {
				color[i] = 0; q.push(i);
				while(!q.empty() & ans){
					long long v = q.front(); q.pop();
					for(auto u : adj[v]){
						if(color[u] == -1){
							color[u] = 1 - color[v];
							q.push(u);
						}
						else if(color[u] == color[v]){
							ans = false;
							break;
						}
					}
				}
			}
		}
		if (!ans) {
			cout << "NOT ";
		}
		cout << "BICOLORABLE.\n";
	}
	return 0;
}