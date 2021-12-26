// https://adventofcode.com/2021/day/3
#include <bits/stdc++.h>
using namespace std;

void first() {
  string s;
  vector<int> v(12, 0);
  int first = 0, second = 0;
  while (cin >> s) {
    for (int i = 0; i < (int) s.size(); ++i) {
      if (s[i] == '0') {
        ++v[i];
      }
    }
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < (int) v.size(); ++i) {
    if (v[i] > 500) {
      cout << i << ": more 0's\n";
      second |= (1<<i);
    } else {
      cout << i << ": ones 1's\n";
      first |= (1<<i);
    }
  }
  cout << first * second << '\n';
}

void second() {
  string s;
  int bit = 11;
  vector<int> v, ans(2, 0);
  while (cin >> s) {
    v.push_back(stoi(s, 0, 2));
  }
  vector<vector<int>> aux(2);
  aux[0] = aux[1] = v;
  while (bit >= 0) {
    for (int i = 0; i < 2; ++i) {
      int n = (int) aux[i].size(), tgt = (1<<bit);
      sort(aux[i].begin(), aux[i].end());
      // count 0's
      int pos = lower_bound(aux[i].begin(), aux[i].end(), tgt)-aux[i].begin();
      // have the least common first; 0 if tie
      if (pos > n/2) {
        pos = n - pos;
        reverse(aux[i].begin(), aux[i].end());
      }
      // reverse if we want the most frequent; 1 if tie
      if (i == 0) {
        pos = n - pos;
        reverse(aux[i].begin(), aux[i].end());
      }
      // add bit to answer
      ans[i] |= (aux[i].front() & (1<<bit));
      // remove evaluated bit
      for (int j = 0; j < n; ++j) {
        aux[i][j] &= (tgt-1);
      }
      aux[i].erase(aux[i].begin()+pos, aux[i].end());
    }
    --bit;
  }
  cout << ans[0] * ans[1] << '\n';
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
