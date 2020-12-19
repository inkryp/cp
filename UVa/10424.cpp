// https://onlinejudge.org/external/104/10424.pdf
#include <bits/stdc++.h>
using namespace std;

void convertToLowerCase(char &c) {
	if ('A' <= c && c <= 'Z') {
		c -= 'A';
		c += 'a';
	}
}

int sumOfDigits(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("o.txt", "w", stdout);
	// freopen("i.txt", "r", stdin);
	cout.setf(ios::fixed);
	cout.precision(2);
	string s1, s2;
	while (getline(cin, s1), getline(cin, s2)) {
		int v1 = 0, v2 = 0;
		for (char &c : s1) {
			convertToLowerCase(c);
			if ('a' <= c && c <= 'z') {
				v1 += c;
				v1 -= 'a';
				++v1;
			}
		}
		for (char &c : s2) {
			convertToLowerCase(c);
			if ('a' <= c && c <= 'z') {
				v2 += c;
				v2 -= 'a';
				++v2;
			}
		}
		while (v1 >= 10) {
			v1 = sumOfDigits(v1);
		}
		while (v2 >= 10) {
			v2 = sumOfDigits(v2);
		}
		if (v1 > v2) {
			swap(v1, v2);
		}
		cout << (double)v1 / v2 * 100 << " %" << endl;
	}
	return 0;
}