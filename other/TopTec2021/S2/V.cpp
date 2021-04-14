// 
#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;
const double EPS = 1e-9;

struct tline {
	long long m, c;
	double p;
};
vector<tline> lines;

double getX(long long m1, long long c1, long long m2, long long c2) {
	return (double) (c1 - c2) / (m2 - m1);
}

void addLine(long long m, long long c) {
	double p = -INF;
	while (!lines.empty()) {
		p = getX(m, c, lines.back().m, lines.back().c);
		if (p < lines.back().p - EPS) {
			lines.pop_back();
		} else {
			break;
		}
	}
	lines.push_back((tline){m, c, p});
}

long long getBestY(long long x) {
	int k = 0, l = 0, r = lines.size() - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (lines[mid].p <= x + EPS) {
			k = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return lines[k].m * x + lines[k].c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			ans = getBestY(a[i]);
		}
		addLine(b[i], ans);
	}
	cout << ans << '\n';
	return 0;
}