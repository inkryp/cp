// 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

long long gcd(const long long& a, const long long& b){
	if (!a) {
		return 1;
	}
	long long x = abs(a), y = abs(b);
	while (y) {
		x %= y;
		swap(x, y);
	}
	if (b / abs(b) > 0) {
		return x;
	}
	return -x;
}
long long lcm(const long long& a, const long long& b) {
	return a / gcd(a, b) * b;
}

struct fraction {
	long long num, den;
	fraction(long long p=0, long long q=1) {
		if (p && q) {
			num = p / gcd(p, q);
			den = q / gcd(p, q);
		} else {
			num = 0; den = 1;
		}
	}
	void change(const long long& p, const long long& q) {
		*this = fraction(p, q);
	}
	fraction operator=(const fraction& f){
		num = f.num; den = f.den;
		return *this;
	}
	fraction operator+=(const fraction& f) {
		if ((*this) == 0) {
			*this = f;
			return *this;
		} 
		if (f == 0) {
			return *this;
		}
		*this = fraction(num * (lcm(den, f.den) / den) + f.num * (lcm(den, f.den) / f.den), lcm(den, f.den));
		return *this;
	}
	fraction operator+(const fraction& f) const {
		return fraction(*this) += f;
	}
	fraction operator-=(const fraction& f) {
		if (*this == 0) {
			*this = fraction(-f.num, f.den);
			return *this;
		}
		if (f == 0) {
			return *this;
		}
		*this = fraction(num * (lcm(den, f.den) / den) - f.num * (lcm(den, f.den) / f.den), lcm(den, f.den));
		return *this;
	}
	fraction operator-(const fraction& f) const {
		return fraction(*this) -= f;
	}
	fraction operator*=(const fraction& f) {
		if (*this == 0 || f == 0) {
			return 0;
		}
		*this = fraction((num / gcd(num, f.den)) * (f.num / gcd(f.num, den)),
			(f.den / gcd(num, f.den)) * (den / gcd(f.num, den)));
		return *this;
	}
	fraction operator*(const fraction& f) const {
		return fraction(*this) *= f;
	}
	fraction operator/=(const fraction& f) {
		*this = fraction(*this * fraction(f.den, f.num));
		return *this;
	}
	fraction operator/(const fraction& f) const {
		return fraction(*this) /= f;
	}
	bool operator>(const fraction& f) const {
		return (double) num / den > (double) f.num / f.den;
	}
	bool operator<(const fraction& f) const {
		return (double) num / den < (double) f.num / f.den;
	}
	bool operator==(const fraction& f) const {
		return num == f.num && den == f.den;
	}
	bool operator!=(const fraction& f) const {
		return (num != f.num || den != f.den);
	}
	bool operator>=(const fraction& f) const {
		return *this > f || *this == f;
	}
	bool operator<=(const fraction& f) const {
		return *this < f || *this == f;
	}
	friend ostream& operator<<(ostream& out, const fraction& f) {
		out << f.num << '/' << f.den;
		return out;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	fraction prob[MAXN][MAXN];
	string a, b;
	while (cin >> a) {
		if (a == "$") {
			break;
		}
		cin >> b;
		int n = (int) a.size();
		map<string, int> prefixes;
		prefixes[""] = 0;
		for (int i = 0; i <= n; ++i) {
			string cur = a.substr(0, i);
			int aux = (int) prefixes.size();
			if (prefixes.find(cur) == prefixes.end()) {
				prefixes[cur] = aux;
			}
			cur = b.substr(0, i);
			aux = (int) prefixes.size();
			if (prefixes.find(cur) == prefixes.end()) {
				prefixes[cur] = aux;
			}
		}

		int m = (int) prefixes.size();
		auto longestSuffix = [&] (string cur) {
			for (int i = 0; i < (int) cur.size(); ++i) {
				string p = cur.substr(i);
				if (prefixes.find(p) != prefixes.end()) {
					return prefixes[p];
				}
			}
			return prefixes[""];
		};

		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				prob[i][j] = 0;
			}
		}
		prob[prefixes[a]][m] = 1; // P(a|a) = 1 & P(a|b) = 0

		for (auto &aux : prefixes) {
			string p = aux.first;
			if ((int) p.size() != n) {
				prob[prefixes[p]][longestSuffix(p + 'H')] = fraction(1, 2);
				prob[prefixes[p]][longestSuffix(p + 'T')] = fraction(1, 2);
			}
		}

		for (int i = m - 1; i >= 0; --i) {
			fraction tmp = fraction(1) - prob[i][i];
			for (int j = 0; j < m + 1; ++j) {
				prob[i][j] /= tmp;
			}
			prob[i][i] = 0;
			for (int k = 0; k < m; ++k) {
				tmp = prob[k][i];
				for (int j = 0; j < m + 1; ++j) {
					prob[k][j] += tmp * prob[i][j];
				}
				prob[k][i] = 0;
			}
		}
		cout << prob[0][m] << '\n';
	}
	return 0;
}