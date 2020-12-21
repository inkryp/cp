// https://onlinejudge.org/external/126/12696.pdf
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t, total = 0; cin >> t;
	while (t--) {
		double l, w, d, sum = 0, weight;
		 cin >> l >> w >> d >> weight;
		 sum += l + w + d;
		 bool allowed = true;
		 if (l > 56.00 || w > 45.00 || d > 25.00 || weight > 7.00) { 
		 	allowed = false;
		 }
		 if (sum <= 125.00 && weight <= 7.00) {
		 	allowed = true;
		 }
		 total += allowed;
		 cout << allowed << endl;
	}
	cout << total << endl;
	return 0;
}