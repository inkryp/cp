// https://onlinejudge.org/external/103/10388.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	auto fun = [&] () {
		return random() / 141 % 2;
	};
	auto wins = [&](int n, string s, string cur) {
		return (int) s.size() + (int) cur.size() == n;
	};
	while (t--) {
		// a -> jane
		// b -> john
		// from top to bottom
		string a, b, cur_a = "", cur_b = "";
		cin >> a >> b;
		const int n = (int) a.size() * 2;
		for (int i = 0; i < 1000; ++i) {
			cur_a.push_back(a[0]);
			a.erase(a.begin());
			cur_b.push_back(b[0]);
			b.erase(b.begin());
			if (cur_a[(int) cur_a.size() - 1] == cur_b[(int) cur_b.size() - 1]) {
				string tmp_reverse;
				cout << "Snap! for ";
				if (fun()) {
					// b calls snap
					cout << "John: ";
					cur_b += cur_a;
					cur_a = "";
					tmp_reverse = cur_b;
				} else {
					// a calls snap
					cout << "Jane: ";
					cur_a += cur_b;
					cur_b = "";
					tmp_reverse = cur_a;
				}
				reverse(tmp_reverse.begin(), tmp_reverse.end());
				cout << tmp_reverse << endl;
			}
			if (a == "") {
				swap(a, cur_a);
			}
			if (b == "") {
				swap(b, cur_b);
			}
			if (wins(n, a, cur_a) || wins(n, b, cur_b)) {
				break;
			}
		}
		if (wins(n, a, cur_a)) {
			cout << "Jane wins.\n";
		} else if (wins(n, b, cur_b)) {
			cout << "John wins.\n";
		} else {
			cout << "Keeps going and going ...\n";
		}
		if (t) {
			cout << '\n';
		}
	}
	return 0;
}