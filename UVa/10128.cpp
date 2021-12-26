// https://onlinejudge.org/external/101/10128.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int n = 14, t, l, r;
  vector<vector<int>> f(n, vector<int>(n, 1));
  vector<int> fact(n-1, 1);
  for (int i = 1; i < n; ++i) {
    fact[i] *= fact[i-1] * i;
  }
  auto C = [&](int i, int j) {
    return fact[i] / fact[j] / fact[i-j];
  };
  // f[see][available]
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 || i > j) {
        f[i][j] = 0;
      }
    }
  }
  for (int i = 2; i < n; ++i) {
    f[1][i] *= f[1][i-1] * (i-1);
  }
  auto sum = [&](int see, int available) {
    int ans = 0;
    for (int i = 0; i < available; ++i) {
      ans += C(available-1, i) * f[see-1][i] * fact[available-1 - i];
    }
    return ans;
  };
  for (int i = 2; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      f[i][j] = sum(i, j);
    }
  }

  // Solve
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    int ans = 0;
    for (int i = l; i <= n-r+1; ++i) {
      ans += C(n-1, i-1) * f[l-1][i-1] * f[r-1][n-i];
    }
    if (n == 1 && l == 1 && r == 1) {
      ans = 1;
    } else if (l == 1 && r != 1) {
      ans = f[r-1][n-1];
    } else if (r == 1) {
      ans = f[l-1][n-1];
    }
    cout << ans << '\n';
  }

  return 0;
}
