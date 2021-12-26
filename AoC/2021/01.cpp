// https://adventofcode.com/2021/day/1
#include <bits/stdc++.h>
using namespace std;

void first() {
  int prev, cur, ans = 0;
  cin >> prev;
  while (cin >> cur) {
    if (cur - prev > 0) {
      ++ans;
    }
    prev = cur;
  }
  cout << ans << '\n';
}

void second() {
  const int n = 3;
  queue<int> qprev, qcur;
  int aux, prev = 0, cur = 0, ans = 0;
  cin >> aux;
  qprev.push(aux);
  prev += aux;
  while (cin >> aux) {
    cur += aux;
    qcur.push(aux);
    if ((int) qcur.size() == n) {
      if (cur > prev) {
        ++ans;
      }
      auto tmp = qprev.front();
      prev -= tmp;
      qprev.pop();
      tmp = qcur.front();
      cur -= tmp;
      qcur.pop();
    }
    prev += aux;
    qprev.push(aux);
  }
  cout << ans << '\n';
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  freopen("i.txt", "r", stdin);
  if (argc == 1) {
    first();
  } else {
    second();
  }
  return 0;
}
