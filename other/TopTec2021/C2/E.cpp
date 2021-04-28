// 
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;

struct Matrix {
	long long mat[MAXN][MAXN];
};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			ans.mat[i][j] = 0;
		}
	}
	for (int i = 0; i < MAXN; ++i) {
		for (int k = 0; k < MAXN; ++k) {
			if (a.mat[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < MAXN; ++j) {
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, long long p) {
	Matrix ans;
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			ans.mat[i][j] = (i == j);
		}
	}
	while (p) {
		if (p & 1) {
			ans = matMul(ans, base);
		}
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	long long n, m, k;
	while (cin >> n >> m >> k) {
		if (n == 0 && m == 0 && k == 0) {
			break;
		}
		Matrix aux, ans;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				ans.mat[i][j] = 0;
				aux.mat[i][j] = 0;
			}
		}

		for (int i = 0; i <= n; ++i) {
			ans.mat[i][0] = 0;
			for (int j = 0; j <= n; ++j) {
				if (i == j) {
					aux.mat[i][j] = 1;
				} else {
					aux.mat[i][j] = 0;
				}
			}
		}
		ans.mat[n][0] = 1;
		char c;
		int i, j;
		for (int y = 0; y < k; ++y) {
			cin >> c >> i;
			--i;
			if (c == 's') {
				cin >> j;
				--j;
				for (int x = 0; x <= n; ++x) {
					swap(aux.mat[i][x], aux.mat[j][x]);
				}
			} else if (c == 'g') {
				++aux.mat[i][n];
			} else {
				for (int x = 0; x <= n; ++x) {
					aux.mat[i][x] = 0;
				}
			}
		}
		aux = matPow(aux, m);
		ans = matMul(aux, ans);
		bool first = true;
		for (int i = 0; i < n; ++i) {
			if (first) {
				cout << ans.mat[i][0];
				first = false;
			} else {
				cout << ' ' << ans.mat[i][0];
			}
		}
		cout << '\n';
	}
	return 0;
}