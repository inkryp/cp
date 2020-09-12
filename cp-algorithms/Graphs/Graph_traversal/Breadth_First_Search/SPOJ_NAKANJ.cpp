#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {
	{-1, -2},
	{-2, -1},
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1},
	{2, -1},
	{1, -2}
};

bool isValid(pair<int, int> p) {
	return 0 <= p.first && p.first < 8
		&& 0 <= p.second && p.second < 8;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		pair<int, int> from = {s[0] - 'a', s[1] - '1'};
		cin >> s;
		pair<int, int> to = {s[0] - 'a', s[1] - '1'};

		vector<vector<bool>> used(8, vector<bool>(8));
		vector<vector<int>> d(8, vector<int>(8));
		queue<pair<int, int>> q;
		used[from.first][from.second] = true;
		d[from.first][from.second] = 0;
		q.push(from);
		while(!q.empty()) {
			pair<int, int> v = q.front();
			q.pop();
			for (auto u : dir) {
				pair<int, int> cur = {v.first + u.first, v.second + u.second};
				if (!isValid(cur)) {
					continue;
				}
				if (!used[cur.first][cur.second]) {
					used[cur.first][cur.second] = true;
					d[cur.first][cur.second] = d[v.first][v.second] + 1;
					q.push(cur);
				}
			}
		}
		cout << d[to.first][to.second] << endl;
	}
	return 0;
}

/*
	https://www.spoj.com/problems/NAKANJ/
*/