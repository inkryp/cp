// https://onlinejudge.org/external/126/12643.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, i, j;
	while (cin >> n >> i >> j) {
		cout << (int)log2(--i ^ --j) + 1 << endl;
	}
	return 0;
}