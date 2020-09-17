// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2725
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int a, b;
	while (cin >> a >> b, a != 0 && b != 0) {
		int aux;
		set<int> alice, betty;
		for (int i = 0; i < a; ++i) {
			cin >> aux;
			alice.insert(aux);
		}
		for (int i = 0; i < b; ++i) {
			cin >> aux;
			betty.insert(aux);
		}
		a = 0; b = 0;
		for (int i : alice) {
			if (betty.count(i) == 0) {
				++a;
			}
		}
		for (int i : betty) {
			if (alice.count(i) == 0) {
				++b;
			}
		}
		cout << min(a, b) << endl;
	}
	return 0;
}