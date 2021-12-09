#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> arr(n);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(order.begin(), order.end(), [&](int a, int b) { return arr[a] < arr[b]; });
  bool ans = true;
  for (int i = 0; i < n; ++i) {
    if (arr[i].second != arr[order[i]].second) {
      ans = false;
      break;
    }
  }
  cout << (ans ? 'Y' : 'N') << '\n';
  
  return 0;
}
