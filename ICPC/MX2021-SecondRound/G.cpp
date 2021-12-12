#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int n, m, ans = 0;
  cin >> n >> m;
  vector<vector<char>> adj(n, vector<char>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      adj[i][j] = s[j];
    }
  }
  vector<pair<int, int>> dir = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0},
    {-1, 1}, {0, 1}, {1, 1}};
  function<bool(int, int)> isValid = [&](int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
  };
  function<void(int, int, int)> dfs = [&](int i, int j, int cur) {
    visited[i][j] = true;
    ans = max(ans, cur);
    for (auto p : dir) {
      int &y = p.first, &x = p.second;
      if (isValid(i+y, j+x)) {
        if (!visited[i+y][j+x] && (adj[i+y][j+x]-adj[i][j])==1) {
          dfs(i+y, j+x, cur+1);
        }
      }
    }
  };
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (adj[i][j] == c) {
          dfs(i, j, 1);
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
