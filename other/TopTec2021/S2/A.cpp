// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	long long n, t, s, d, cur = (1LL << 60), ans, aux; cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> s >> d;
		if (s >= t) {
			if (cur > s) {
				cur = s;
				ans = i;
			}
		} else {
			// s < t; s + d*p >= t ===> d*p >= t-s
			aux = (t - s) / d;
			aux += ((t - s) % d == 0) ? 0 : 1;
			aux = s + d * aux;
			if (aux < cur) {
				cur = aux;
				ans = i;
			} 
		}
	}
	cout << ans << '\n';
	return 0;
}