// https://onlinejudge.org/external/17/1709.pdf
#include <bits/stdc++.h>
using namespace std;

double price(const int &p, const int &a, const int &b,
	const int &c, const int &d, const int &i) {
	return p * ((double)sin(a * i + b) + cos(c * i + d) + 2);
}

int main() {
	int p, a, b, c, d, n;
	while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF) {
		double ans = DBL_MIN, cur_max = DBL_MIN;
		for (int i = 1; i <= n; ++i) {
			double cur = price(p, a, b, c, d, i);
			cur_max = max(cur_max, cur);
			ans = max(ans, cur_max - cur);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);	cout.tie(0);
// 	cout.setf(ios::fixed);
// 	cout.precision(10);
// 	int p, a, b, c, d, n;
// 	while (cin >> p >> a >> b >> c >> d >> n) {
// 		double ans = DBL_MIN, cur_max = DBL_MIN;
// 		for (int i = 1; i <= n; ++i) {
// 			double cur = price(p, a, b, c, d, i);
// 			cur_max = max(cur_max, cur);
// 			ans = max(ans, cur_max - cur);
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);	cout.tie(0);
// 	cout.setf(ios::fixed);
// 	cout.precision(10);
// 	// freopen("i.txt", "r", stdin);
// 	// freopen("o.txt", "w", stdout);
// 	int p, a, b, c, d, n;
// 	while (cin >> p >> a >> b >> c >> d >> n) {
// 		double ans = DBL_MIN, cur_max;
// 		priority_queue< double, vector<double>, greater<double> > qmin;
// 		cur_max = price(p, a, b, c, d, 1);
// 		for (int i = 2; i <= n; ++i) {
// 			double cur = price(p, a, b, c, d, i);
// 			if (cur > cur_max) {
// 				if (!qmin.empty()) {
// 					ans = max(ans, cur_max - qmin.top());
// 					while (!qmin.empty()) {
// 						qmin.pop();
// 					}
// 				}
// 				cur_max = cur;
// 			} else {
// 				qmin.push(cur);
// 			}
// 		}
// 		if (!qmin.empty()) {
// 			ans = max(ans, cur_max - qmin.top());
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }