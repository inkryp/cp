#include <bits/stdc++.h>
using namespace std;

struct {
  int t=-1, dir=-1;
} now;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int n, t, d;
  vector<queue<int>> v(2, queue<int>());
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> d;
    v[d].push(t);
  }
  if (!v[0].empty()) {
    now.dir = 0;
    now.t = v[0].front();
  }
  if (!v[1].empty()) {
    if (now.t == -1 || v[1].front() < now.t) {
      now.dir = 1;
      now.t = v[1].front(); v[1].pop();
    } else {
      v[0].pop();
    }
  }
  while (!v[0].empty() || !v[1].empty()) {
    while (!v[now.dir].empty() && (v[now.dir].front()-now.t)<=10) {
      now.t = max(now.t, v[now.dir].front()); v[now.dir].pop();
    }
    if (v[now.dir].empty()) {
      now.dir ^= 1;
    } else {
      if (v[now.dir^1].empty() || v[now.dir].front() < v[now.dir^1].front()) {
        now.t = v[now.dir].front(); v[now.dir].pop();
        continue;
      } else {
        now.dir ^= 1;
      }
    }
    if (!v[now.dir].empty()) {
      now.t = max(now.t+10, v[now.dir].front()); v[now.dir].pop();
    }
  }
  cout << now.t+10 << '\n';
  
  return 0;
}
