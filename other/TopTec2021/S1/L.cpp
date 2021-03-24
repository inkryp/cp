// 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
int n, mat[MAXN][MAXN], sal[2 * MAXN];
vector< pair<int, int> > edges;

void build(const vector<int> &ls, int cur) {
	if (ls.size() == 1) {
		edges.push_back({ls[0], cur});
		return;
	}
	int root = -1;
	for (auto &u : ls) {
		for (auto &v : ls) {
			root = max(root, mat[u][v]);
		}
	}
	vector< vector<int> > childs;
	for (int i = 0; i < (int) ls.size(); ++i) {
		bool found = false;
		for (int j = 0; j < (int) childs.size(); ++j) {
			if (mat[childs[j].back()][ls[i]] < root) {
				childs[j].push_back(ls[i]);
				found = true;
				break;
			}
		}
		if (!found) {
			childs.push_back({ls[i]});
		}
	}
	int v = n++;
	sal[v] = root;
	if (cur != 0) {
		edges.push_back({v, cur});
	}
	for (int i = 0; i < (int) childs.size(); ++i) {
		build(childs[i], v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	int ans = n + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	vector<int> ls(n);
	for (int i = 0; i < n; ++i) {
		sal[i] = mat[i][i];
		ls[i] = i;
	}
	build(ls, 0);
	cout << n << '\n' << sal[0];
	for (int i = 1; i < n; ++i) {
		cout << ' ' << sal[i];
	}
	cout << '\n' << ans << '\n';
	for (auto &[u, v] : edges) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
	return 0;
}