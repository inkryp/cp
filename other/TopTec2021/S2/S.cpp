// 
#include <bits/stdc++.h>
using namespace std;

#define log2_ll(x) (63 - __builtin_clzll((long long)(x)))

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n;
	cin >> n;
	long long lead, steps = -1, ans = 0;
	vector<long long> p(n), diff(n - 1);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p.rbegin(), p.rend());
	for (int i = 0; i < n - 1; ++i) {
		diff[i] = p[i] - p[i + 1];
	}
	lead = diff[0];
	for (int i = 1; i < (int) diff.size(); ++i) {
		long long times = log2_ll(i);
		if (diff[i] * times >= lead && times) {
			steps = i;
			break;
		}
		lead -= diff[i] * times;
		ans += diff[i] * (times + 1);
	}
	steps = ((steps == -1) ? n - 1 : steps);
	long long times = log2_ll(steps), last = lead / times;
	lead -= last * times;
	ans += last * (times + 1) + lead;
	cout << ans << '\n';
	return 0;
}