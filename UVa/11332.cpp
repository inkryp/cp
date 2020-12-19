// https://onlinejudge.org/external/113/11332.pdf
#include <bits/stdc++.h>
using namespace std;

int d(int &n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		while (n >= 10) {
			n = d(n);
		}
		cout << n << endl;
	}
	return 0;
}