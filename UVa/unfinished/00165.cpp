// https://onlinejudge.org/external/1/165.pdf
#include <bits/stdc++.h>
using namespace std;

int solve(int limit, int amtTypes) {
  int mx = 0, reach;
  vector<int> coins, ans;
  function<void(int)> mk = [&](int cur) {
    coins.push_back(cur);
    int n = (int) coins.size();
    if (n == amtTypes) {
      if (reach > mx) {
        
      }
    } else if () {

    }
  };
  mk(1);
  return mx;
}

int main() {
  // vector<vector<int>> v(9, vector<int>());
  // for (int i = 1; i < 9; ++i) {
  //   for (int j = 1; j < 9; ++j) {
  //     if (i + j > 9) {
  //       break;
  //     }
  //     v[i][j] = solve(i, j);
  //   }
  // }


  // int h, k;
  // scanf("%d %d", &h, &k);
  // while (true) {


  //   scanf("%d %d", &h, &k);
  //   if (h == 0 && k == 0) {
  //     break;
  //   } else {
  //     printf("\n");
  //   }
  // }
  return 0;
}
