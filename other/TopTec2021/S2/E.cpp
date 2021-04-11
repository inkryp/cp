// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	long long n, x, y, white, black;
	cin >> n >> x >> y;
	white = (x - 1) + (y - 1);
	black = (n - x) + (n - y);
	cout << ((white <= black) ? string("White") : string("Black")) << '\n';
	return 0;
}