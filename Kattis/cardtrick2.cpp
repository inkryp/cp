// https://open.kattis.com/problems/cardtrick2
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  vector<vector<int>> ans(13, vector<int>());
  for (int i = 0; i < 13; ++i) {
    ans[i].assign(i+1, -1);
    queue<int> q;
    vector<int> v(i+1);
    for (int j = 0; j <= i; ++j) {
      q.push(j);
    }
    for (int j = 1; j <= i+1; ++j) {
      for (int k = 0; k < j; ++k) {
        auto u = q.front();
        q.pop();
        q.push(u);
      }
      v[j-1] = q.front();
      q.pop();
    }
    for (int j = 0; j <= i; ++j) {
      ans[i][v[j]] = j+1;
    }
  }

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cout << ans[n-1][i] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}
