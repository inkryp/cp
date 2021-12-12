#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  long long n, c;
  string s;
  cin >> n >> s;
  c = stoi(s);
  s = s.back();
  if (s == "G") {
    c <<= 10;
  } else if (s == "T") {
    c <<= 20;
  }
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long cur = 0;
  int r = 0, rg = n, ans = -1;
  for (int i = 0; i < n; ++i) {
    while (r < n && cur + v[r] <= c) {
      cur += v[r++];
    }
    if (r < n && r-i < rg) {
      ans = i+1;
      rg = r-i;
    }
    cur -= v[i];
  }
  cout << rg << ' ' << ans << '\n';

  return 0;
}
