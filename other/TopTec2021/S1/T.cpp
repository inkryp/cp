// 
#include <bits/stdc++.h>
using namespace std;

struct ppl {
	int h, w, idx;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, height, width; cin >> n;
		vector<ppl> a(2 * n);
		vector<int> ans(n, -1);
		set< pair<int, int> > s;
		for (int i = 0; i < n; ++i) {
			cin >> height >> width;
			a[i].h = a[i + n].w = height;
			a[i].w = a[i + n].h = width;
			a[i].idx = a[i + n].idx = i;
		}
		sort(a.begin(), a.end(),
			[](const ppl &a, const ppl &b){
				return tie(a.h, a.w, a.idx) < tie(b.h, b.w, b.idx);
			});
		int last = 0;
		for (int i = 0; i < 2 * n; ++i) {
			if (a[i - 1].h < a[i].h && i) {
				for (int j = last; j < i; ++j) {
					s.insert({a[j].w, a[j].idx});
				}
				last = i;
			}
			int check = 0;
			for (auto &[w, idx] : s) {
				if (check == 2) {
					break;
				}
				++check;
				if (w < a[i].w && idx != a[i].idx) {
					ans[a[i].idx] = idx + 1;
				}
			}
		}
		for (auto &x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}