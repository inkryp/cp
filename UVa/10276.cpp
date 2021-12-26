// https://onlinejudge.org/external/102/10276.pdf
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50+10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int t, aux = 2;
  vector<int> v(MAXN, 0);
  v[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    v[i] = v[i-1] + aux;
    if (i % 2 == 0) {
      aux += 2;
    }
  }

  cin >> t;
  while (t--) {
    cin >> aux;
    cout << v[aux] << '\n';
  }

  return 0;
}
