// https://adventofcode.com/2021/day/6
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  freopen("i.txt", "r", stdin);

  const int n = 9;
  string s;
  vector<long long> v(n, 0), cur;
  auto read = [&]() {
    getline(cin, s);
    while (s.find(",") != string::npos) {
      ++v[stoll(s)];
      s = s.substr(s.find(",")+1);
    }
    ++v[stoll(s)];
  };
  auto solve = [&](int t) {
    long long ans = 0;
    cur = v;
    while (t--) {
      long long new_borns = cur[0];
      for (int i = 0; i < n-1; ++i) {
        cur[i] = cur[i+1];
      }
      cur[6] += new_borns;
      cur.back() = new_borns;
    }
    for (int i = 0; i < n; ++i) {
      ans += cur[i];
    }
    return ans;
  };

  auto first = [&]() {
    cout << solve(80) << '\n';
  };
  auto second = [&]() {
    cout << solve(256) << '\n';
  };

  read();
  if (argc == 1) {
    first();
  } else {
    second();
  }
  return 0;
}
