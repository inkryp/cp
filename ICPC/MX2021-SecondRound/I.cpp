#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    while (n > 9) {
      ++ans;
      int cur = 1;
      while (n > 0) {
        cur *= n % 10;
        n /= 10;
      }
      n = cur;
    }
    cout << ans << '\n';
  }

  return 0;
}
