// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	long long n, k;
	cin >> n >> k;
	auto f = [&](int color) {
		return (long long)(ceil((double)(color * n)/k));
	};
	cout << f(2) + f(5) + f(8) << '\n';
	return 0;
}