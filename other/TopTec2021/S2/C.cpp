// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int b, k, ans = 0, tmp; cin >> b >> k;
	while (k--) {
		cin >> tmp;
		ans += ((tmp & 1) & (b & 1)) ? 1 : 0;
	}
	ans = (b & 1) ? ans : (tmp & 1);
	cout << ((ans & 1) ? "odd" : "even") << '\n'; 
	return 0;
}