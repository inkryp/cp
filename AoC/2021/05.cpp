// https://adventofcode.com/2021/day/5
#include <bits/stdc++.h>
using namespace std;

int sgn(int x) { return (x > 0) - (x < 0); }

struct Point {
  int x, y;
  Point(int _x=0, int _y=0) : x(_x), y(_y) {}
  bool operator<(Point pt) const { return tie(x, y) < tie(pt.x, pt.y); }
  bool operator==(Point pt) const { return tie(x, y) == tie(pt.x, pt.y); }
  bool operator>(Point pt) const { return tie(x, y) > tie(pt.x, pt.y); }
  bool operator<=(Point pt) const { return (*this) < pt || (*this) == pt; }
  Point& operator+=(const Point& other) { x += other.x; y += other.y; return *this; }
};

struct Segment {
  Point from, to;
  Segment(Point _from, Point _to) : from(_from), to(_to) {
    if (_from > _to) {
      swap(from, to);
    }
  }
};

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);  cout.tie(0);
  freopen("i.txt", "r", stdin);

  int x, y, i, j, mx = -1;
  vector<Segment> all;
  vector<vector<int>> aux;
  auto read = [&]() {
    while (scanf("%d,%d -> %d,%d", &x, &y, &i, &j) != EOF) {
      Point from = Point(x, y), to = Point(i, j);
      Segment cur = Segment(from, to);
      all.push_back(cur);
      mx = max(mx, max(x, max(y, max(i, j))));
    }
    mx += 10;
    aux.assign(mx, vector<int>(mx, 0));
  };

  auto first = [&]() {
    int ans = 0;
    for (auto &s : all) {
      Point &from = s.from, &to = s.to;
      if (from.x - to.x == 0) {
        for (int i = from.y; i <= to.y; ++i) {
          ++aux[from.x][i];
        }
      } else if (from.y - to.y == 0) {
        for (int i = from.x; i <= to.x; ++i) {
          ++aux[i][from.y];
        }
      }
    }
    for (int i = 0; i < mx; ++i) {
      for (int j = 0; j < mx; ++j) {
        if (aux[i][j] > 1) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  };
  auto second = [&]() {
    int ans = 0;
    for (auto &s : all) {
      Point &from = s.from, &to = s.to;
      if (from.x - to.x == 0) {
        for (int i = from.y; i <= to.y; ++i) {
          ++aux[from.x][i];
        }
      } else if (from.y - to.y == 0) {
        for (int i = from.x; i <= to.x; ++i) {
          ++aux[i][from.y];
        }
      } else if (abs(from.x - to.x) == abs(from.y - to.y)) {
        for (Point s = from; s <= to; s += Point(1, sgn(to.y-from.y))) {
          ++aux[s.x][s.y];
        }
      }
    }
    for (int i = 0; i < mx; ++i) {
      for (int j = 0; j < mx; ++j) {
        if (aux[i][j] > 1) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  };

  read();
  if (argc == 1) {
    first();
  } else {
    second();
  }
  return 0;
}
