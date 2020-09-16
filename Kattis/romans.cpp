// https://open.kattis.com/problems/romans
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	const double k = 1000 * ((double) 5280 / 4854);
	double x; cin >> x;
	cout << (int)(round(k * x)) << endl;
	return 0;
}