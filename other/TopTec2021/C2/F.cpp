// UNSOLVED 
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector< vector<int> > g;
  int n;

  function<bool(int)> ignore;

  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};

template <typename T>
vector<int> find_topsort(const digraph<T> &g) {
  vector<int> deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    deg[g.edges[id].to]++;
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (int id : g.g[i]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != g.n) {
    return vector<int>();
  }
  return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n, m;
		cin >> n >> m;
		digraph<int> g(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			g.add(y, x);
		}
		vector<int> cnt(n), order = find_topsort(g);
		for (int i = 0; i < n; ++i) {
			cout << "TEST: " << g.edges[i].from << endl;
		}
		cout << "Scenario #" << tc << ":\n\n";
		for (int i = 0; i < n; ++i) {
			cout << cnt[i] << ' ' << order[i] << '\n';
		}
		cout << '\n';
	}
	return 0;
}