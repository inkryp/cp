// https://onlinejudge.org/external/110/11044.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		cout << (long long)(ceil((double)(n - 2) / 3) * ceil((double)(m - 2) / 3)) << endl;
	}
	return 0;
}