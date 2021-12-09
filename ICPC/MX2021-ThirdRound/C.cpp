#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int b, l, cnt = 0, sgn, idx, ans;
  cin >> b >> l;
  vector<int> d(l);
  sgn = (l&1) ? -1 : 1; ++b;
  for (int i = 0; i < l; ++i) {
    cin >> d[i];
    cnt += sgn * d[i];
    cnt = (cnt + b) % b;
    sgn *= -1;
  }
  sgn = (l&1) ? -1 : 1;
  idx = ans = -1;
  for (int i = 0; i < l; ++i) {
    int reach = (sgn * d[i]) - cnt;
    reach *= sgn;
    reach = (reach+b) % b;
    if (0 <= reach && reach < b && reach < d[i]) {
      idx = i+1;
      ans = reach;
      break;
    }
    sgn *= -1;
  }
  if (cnt == 0) {
    idx = ans = 0;
  }
  cout << idx << ' ' << ans << '\n';
  
  return 0;
}
