#include <bits/stdc++.h>
using namespace std;

#define what(x) cerr << #x << " = " << x << '\n';
const int MAXN = 1e5+10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int q, t, i, cnt = 1;
  stack<int> order;
  set<int> death;
  cin >> q;
  vector<queue<int>> adj(MAXN);
  order.push(0);

  function<bool(int)> dfs = [&](int v) {
    if (death.count(v) == 0) {
      return true;
    }
    while (!adj[v].empty()) {
      int u = adj[v].front();
      order.push(u);
      adj[v].pop();
      return dfs(u);
    }
    return false;
  };

  while (q--) {
    cin >> t >> i;
    // i had a child, else i died
    if (t==1) {
      adj[--i].push(cnt++);
    } else {
      death.insert(--i);
      while (!dfs(order.top())) {
        order.pop();
      }
      cout << order.top()+1 << '\n';
    }
  }
  
  return 0;
}
