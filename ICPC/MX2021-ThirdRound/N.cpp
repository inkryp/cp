#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

template <typename T>
struct fenwick {
  std::vector<T> ft;
  fenwick(int m) { ft.assign(m+1, { }); }
  fenwick(const std::vector<T> &f) { build(f); }
  fenwick(const int &m, const std::vector<T> &info) {
    std::vector<T> f(m+1, 0);
    for (int i = 0; i < (int) info.size(); ++i) {
      ++f[info[i]];
    }
    build(f);
  }
  void build(const std::vector<T> &f) {
    int m = (int) f.size()-1;
    ft.assign(m+1, { });
    for (int i = 1; i <= m; ++i) {
      ft[i] += f[i];
      if (i+LSOne(i) <= m) {
        ft[i+LSOne(i)] += ft[i];
      }
    }
  }
  T get(int j) {
    T sum{};
    for (; j; j -= LSOne(j)) {
      sum += ft[j];
    }
    return sum;
  }
  T get(int i, int j) { return get(j) - get(i-1); }
  void update(int i, T val) {
    for (; i < (int) ft.size(); i += LSOne(i)) {
      ft[i] += val;
    }
  }
  int select(T tgt) {
    int p = 1, idx = 0;
    while (p*2 < (int) ft.size()) {
      p *= 2;
    }
    while (p) {
      if (tgt > ft[idx+p]) {
        tgt -= ft[idx+p];
        idx += p;
      }
      p /= 2;
    }
    return idx+1;
  }
};

template <typename T>
struct rupq {
  fenwick<T> ft;
  rupq(int m) : ft(fenwick<T>(m)) { }
  rupq(const std::vector<T> &f) : ft(fenwick<T>(f)) { }
  void update(int ui, int uj, T val) {
    ft.update(ui, val);
    ft.update(uj+1, -val);
  }
  T get(int j) { return ft.get(j); }
};

template <typename T>
struct rurq {
  rupq<T> pt;
  fenwick<T> ft;
  rurq(int m) : pt(rupq<T>(m)), ft(fenwick<T>(m)) { }
  rurq(const std::vector<T> &f) : pt(rupq<T>(f)), ft(fenwick<T>(f)) { }
  void update(int ui, int uj, T val) {
    pt.update(ui, uj, val);
    ft.update(ui, val*(ui-1));
    ft.update(uj+1, -val*uj);
  }
  T get(int j) { return pt.get(j)*j - ft.get(j); }
  T get(int i, int j) { return get(j) - get(i-1); }
};

struct query {
  int l, r, val;
  query(int _l=0, int _r=1, int _val=-1) : l(_l), r(_r+_l), val(_val) {}
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);

  int y, n, a, p, f, idx=0;
  cin >> y >> n;
  vector<int> pos(y+1, -1), order(y+1), ans(n, 0), ord(n);
  vector<query> q(n);
  fenwick<int> ft(y);
  for (int i = 1; i <= y; ++i) {
    cin >> pos[i];
  }
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int a, int b) { return pos[a] > pos[b]; });
  for (int i = 0; i < n; ++i) {
    cin >> a >> p >> f;
    q[i] = query(a, f, p);
  }
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int a, int b) { return q[a].val > q[b].val; });
  for (int i = 0; i < n; ++i) {
    query &cur = q[ord[i]];
    while (pos[order[idx]] >= cur.val && idx < y) {
      ft.update(order[idx], 1);
      ++idx;
    }
    if (cur.val > pos[cur.l]) {
      ans[ord[i]] = ft.get(cur.l, cur.r);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}
