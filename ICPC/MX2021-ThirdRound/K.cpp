#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int t, d, m;
  cin >> t >> d >> m;
  vector<int> arr(m+2, 0);
  for (int i = 1; i <= m; ++i) {
    cin >> arr[i];
  }
  arr[m+1] = d;
  bool ans = false;
  for (int i = 1; i <= m+1; ++i) {
    if (arr[i]-arr[i-1] >= t) {
      ans = true;
    }
  }
  cout << (ans ? 'Y' : 'N') << '\n';
  
  return 0;
}
