// https://onlinejudge.org/external/7/750.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt, a, b, line;
  scanf("%d", &tt);

  vector<int> sol;
  vector<bool> used;

  auto valid = [&](int row, int col) {
    for (int i = 0; i < col; ++i) {
      if ((sol[i] == row) || (abs(sol[i] - row) == abs(i - col))) {
        return false;
      }
    }
    return true;
  };

  function<void(int)> mk = [&](int c) {
    if (c == 8) {
      printf("%2d      %d", ++line, sol[0]+1);
      for (int i = 1; i < 8; ++i) {
        printf(" %d", sol[i]+1);
      }
      printf("\n");
      return;
    }
    for (int i = 0; i < 8; ++i) {
      if ((c == b) && (i != a))  {
        continue;
      }
      if (valid(i, c)) {
        sol[c] = i;
        mk(c + 1);
      }
    }
  };

  while (tt--) {
    scanf("%d %d", &a, &b);
    --a, --b; line = 0;
    sol.assign(8, 0);
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    mk(0);
    if (tt) {
      printf("\n");
    }
  }

  return 0;
}
