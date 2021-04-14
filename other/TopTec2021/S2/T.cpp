// 
#include <bits/stdc++.h>
using namespace std;

struct range {
	double linear, square, amt;
	double average() {
		return ((double) linear) / amt;
	}
	range(int a = 0) : linear(1.0 * a), square(1.0 * a * a), amt(1) {}
	range operator+=(const range &other) {
		linear += other.linear;
		square += other.square;
		amt += other.amt;
		return *this;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(20);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	auto solve = [&] (const vector<int> &a) {
		vector<range> pos;
		for (auto &x : a) {
			pos.push_back(x);
			int r = (int) pos.size() - 1;
			while (r > 0 && pos[r].average() <= pos[r - 1].average()) {
				pos[--r] += pos[r];
				pos.pop_back();
			}
		}
		double ans = 0;
		for (auto &pt : pos) {
			ans += pt.square + pt.amt * pt.average() * pt.average() - 2 * pt.average() * pt.linear;
		}
		return ans;
	};
	cout << solve(x) + solve(y) << '\n'; 
	return 0;
}