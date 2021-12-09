#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  long long a = 1, b = 1, cnt = 1, n;
  cin >> n;
  vector<pair<long long, string>> fib;
  vector<string> ans;
  while (b <= n) {
    b += a;
    if (n % b == 0) {
      fib.push_back({b, string(cnt, 'A') + 'B'});
    }
    ++cnt;
    a = b - a;
  }
  function<bool(long long, int)> solve = [&](long long cur, int idx) {
    if (idx == -1) {
      return false;
    }
    if (cur == 1) {
      return true;
    }
    if (cur % fib[idx].first == 0) {
      ans.push_back(fib[idx].second);
      if (solve(cur/fib[idx].first, idx)) {
        return true;
      }
      ans.pop_back();
    }
    return solve(cur, idx-1);
  };
  if (solve(n, (int) fib.size()-1)) {
    for (int i = 0; i < (int) ans.size(); ++i) {
      cout << ans[i];
    }
    cout << '\n';
  } else {
    cout << "IMPOSSIBLE\n";
  }
  
  return 0;
}
