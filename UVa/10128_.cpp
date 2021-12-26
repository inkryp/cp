// https://onlinejudge.org/external/101/10128.pdf
// Precompute the answers!
// Actual solution does not use precomputed values.
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  freopen("ans.txt", "w", stdout);

  const int MAXN = 13;
  long long fact[MAXN] = {1};
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = fact[i-1]*(i+1);
  }
  for (int n = 1; n <= MAXN; ++n) {
    map<pair<int, int>, long long> ans;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do {
      int l = 0, r = 0, aux;
      aux = v[0];
      for (int i = 0; i < n; ++i) {
        if (aux <= v[i]) {
          ++l;
          aux = v[i];
        }
      }
      aux = v.back();
      for (int i = n-1; i >= 0; --i) {
        if (aux <= v[i]) {
          ++r;
          aux = v[i];
        }
      }
      ++ans[{l, r}];
    } while (next_permutation(v.begin(), v.end()));
    cout << n << '\n';
    long long aux = 0;
    for (auto p : ans) {
      aux += p.second;
      cout << "{" << p.first.first << ", " << p.first.second << "} = " << p.second << '\n';
    }
    assert(aux == fact[n-1]);
    cout << '\n';
  }

  return 0;
}
