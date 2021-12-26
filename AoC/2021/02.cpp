// https://adventofcode.com/2021/day/2
#include <bits/stdc++.h>
using namespace std;

void first() {
  string s;
  long long amt, depth = 0, hz = 0;
  while (cin >> s >> amt) {
    if (s[0] == 'f') {
      hz += amt;
    } else if (s[0] == 'd') {
      depth += amt;
    } else {
      depth -= amt;
    }
  }
  cout << depth * hz << '\n';
}

void second() {
  string s;
  long long aim = 0, hz = 0, depth = 0, aux;
  while (cin >> s >> aux) {
    if (s[0] == 'f') {
      hz += aux;
      depth += aim * aux;
    } else if (s[0] == 'd') {
      aim += aux;
    } else {
      aim -= aux;
    }
  }
  cout << depth * hz << '\n';
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
