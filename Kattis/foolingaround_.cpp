// https://open.kattis.com/problems/foolingaround
// Precompute the answers!
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+10;

long long _sieve_size;
bitset<MAXN> bs;
vector<long long> p;

void sieve(long long upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i < _sieve_size; ++i) {
    if (bs[i]) {
      for (long long j = i * i; j < _sieve_size; j += i) {
        bs[j] = 0;
      }
      p.push_back(i);
    }
  }
}

bool isPrime(long long n) {
  if (n < _sieve_size) {
    return bs[n];
  }
  for (int i = 0; i < (int) p.size() && p[i]*p[i] <= n; ++i) {
    if (n % p[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  int n = 1e9+2;

  freopen("ans.txt", "w", stdout);
  sieve(n);
  cerr << "HERE\n";

  int cnt = 1;
  set<int> bob;
  for (int i = 1; i <= n; ++i) {
    bool add = true;
    if (isPrime(i+1)) {
      add = false;
    } else {
      for (auto &x : bob) {
        auto tgt = i-x;
        if (bob.find(tgt) == bob.end() && isPrime(tgt+1)) {
          add = false;
        }
      }
    }
    if (add) {
      cerr << cnt++ << ' ' << i << '\n';
      bob.insert(i);
    }
  }
  cout << '{';
  for (auto &x : bob) {
    cout << x << ',';
  }
  cout << "}\n";
  
  return 0;
}
