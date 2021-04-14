// 
#include <bits/stdc++.h>
using namespace std;

typedef long double angle;
const angle PI = acos(-1.0);

struct pt {
	double x, y;
	pt(double x = 0, double y = 0) : x(x), y(y) {}
	pt operator=(const pt &p) {
		x = p.x;
		y = p.y;
		return *this;
	}
	pt operator+=(const pt &p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	pt operator+(const pt &p) const {
		return pt(*this) += p;
	}
	pt operator-=(const pt &p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	pt operator-(const pt &p) const {
		return pt(*this) -= p;
	}
	pt operator*=(const pt &p) {
		x *= p.x;
		y *= p.y;
		return *this;
	}
	pt operator*(const pt &p) const {
		return pt(*this) *= p;
	}
	pt operator/=(const pt &p) {
		x /= p.x;
		y /= p.y;
		return *this;
	}
	pt operator/(const pt &p) const {
		return pt(*this) /= p;
	}
	friend ostream& operator<<(ostream& out, const pt &p) {
		out << p.x << ' ' << p.y;
		return out;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> allChildren(n);
	vector<pt> coor(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	auto circle = [&] (const pt& p, const angle &rad) {
		return pt(p.x + cos(rad), p.y + sin(rad));
	};
	function<int(int, int)> dfs = [&] (int cur, int prev) {
		allChildren[cur] = 1;
		for (auto &u : adj[cur]) {
			if (u != prev) {
				allChildren[cur] += dfs(u, cur);
			}
		}
		return allChildren[cur];
	};
	function<void(int, int, angle, angle)> Build = [&] (int cur, int prev, angle from, angle to) {
		if (allChildren[cur] == 1) {
			return;
		}
		angle rot = (to - from) / (allChildren[cur] - 1);
		int cnt = 0;
		for (auto &u : adj[cur]) {
			if (u != prev) {
				angle here = from + (cnt * rot), next = from + ((cnt + allChildren[u]) * rot);
				coor[u] = circle(coor[cur], here);
				cnt += allChildren[u];
				Build(u, cur, here, next);
			}
		}
	};
	dfs(0, -1);
	Build(0, -1, 0, PI);
	for (auto &p : coor) {
		cout << p << '\n';
	}
	return 0;
}