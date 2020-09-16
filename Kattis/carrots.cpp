// https://open.kattis.com/problems/carrots
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, p; cin >> n >> p;
	string s;
	for (int i = 0; i <= n; ++i) {
		getline(cin, s);
	}
	cout << p << endl;
	return 0;
}