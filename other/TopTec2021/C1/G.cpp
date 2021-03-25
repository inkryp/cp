// 
#include <bits/stdc++.h>
using namespace std;

struct info {
	int pos, zero, neg;
	info(void) : pos(0), zero(0), neg(0) {}
	info(const int &pos, const int &zero, const int &neg) : pos(pos), zero(zero), neg(neg) {}
	info operator+ (const info& other) {
		info tmp = info();
		tmp.pos = this->pos + other.pos;
		tmp.zero = this->zero + other.zero;
		tmp.neg = this->neg + other.neg;
		return tmp;
	}
};

struct Tree {
	typedef info T;
	T unit = info();
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = info()) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k, tmp, l, r; char c;
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	while (cin >> n >> k) {
		Tree st(n);
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			if (tmp > 0) {
				st.update(i, info(1, 0, 0));
			} else if (tmp == 0) {
				st.update(i, info(0, 1, 0));
			} else {
				st.update(i, info(0, 0, 1));
			}
		}
		while (k--) {
			cin >> c >> l >> r;
			if (c == 'C') {
				info tmp;
				if (r > 0) {
					tmp.pos = 1;
				} else if (r == 0) {
					tmp.zero = 1;
				} else {
					tmp.neg = 1;
				}
				st.update(--l, tmp);
			} else {
				info ans = st.query(--l, r);
				if (ans.zero > 0) {
					cout << '0';
				} else if (ans.neg & 1) {
					cout << '-';
				} else {
					cout << '+';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}