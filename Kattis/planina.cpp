// https://open.kattis.com/problems/planina
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, ans = 2; cin >> n;
	for (int i = 0; i < n; ++i) {
		ans *= 2;
		--ans;
	}
	cout << ans * ans << endl;
	return 0;
}