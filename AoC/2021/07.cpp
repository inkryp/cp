// https://adventofcode.com/2021/day/7
#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
  tree_order_statistics_node_update> ost;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  freopen("i.txt", "r", stdin);

  string s;
  vector<int> v, cur, rg, f;
  auto read = [&]() {
    getline(cin, s);
    while (s.find(",") != string::npos) {
      v.push_back(stoi(s));
      s = s.substr(s.find(",")+1);
    }
    v.push_back(stoi(s));
  };

  auto first = [&]() {
    int n = (int) v.size();
    ost tree;
    for (int i = 0; i < n; ++i) {
      tree.insert(v[i]);
    }
    long long ans = 0, tgt = *tree.find_by_order(n/2);
    for (int i = 0; i < n; ++i) {
      ans += abs(v[i]-tgt);
    }
    cout << ans << '\n';
  };
  auto second = [&]() {
    
  };

  read();
  if (argc == 1) {
    first();
  } else {
    second();
  }
  return 0;
}
