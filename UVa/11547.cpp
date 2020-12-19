// https://onlinejudge.org/external/115/11547.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (abs(((((((n * 567) / 9) + 7492) * 235) / 47) - 498)) % 100) / 10 << endl;
	}
	return 0;
}