// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, ones = 0, twos = 0, tmp; cin >> n;
		while (n--) {
			cin >> tmp;
			if (tmp == 1) {
				++ones;
			} else {
				++twos;
			}
		}
		if (ones & 1 || (twos & 1) && ones < 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}