// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, idx = 0; cin >> n;
	vector<int> first(n), second(n), third(n);
	for (int i = n / 2; i >= 0; --i) {
		first[idx++] = i;
	}
	for (int i = 1; i <= n / 2; ++i) {
		first[idx++] = i;
	}
	idx = 0;
	for (int i = 0; i <= n / 2; ++i) {
		second[idx++] = 2 * (i + 1) - 1;
	}
	for (int i = n / 2; i > 0; --i) {
		second[idx++] = 2 * i - 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < first[i]; ++j) {
			cout << '*';
		}
		for (int j = 0; j < second[i]; ++j) {
			cout << 'D';
		}
		for (int j = 0; j < first[i]; ++j) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}