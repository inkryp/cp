// https://onlinejudge.org/external/9/947.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	auto check = [] (string key, string s, const pair<int, int>& info) {
		pair<int, int> ans = {0, 0};
		vector<int> pos;
		map<char, int> info_key, info_s; 
		for (int i = 0; i < (int) s.size(); ++i) {
			if (key[i] == '0') {
				return false;
			}
			if (s[i] == key[i]) {
				++ans.first;
			} else {
				++info_key[key[i]];
				++info_s[s[i]];
			}
		}
		for (auto i : info_s) {
			ans.second += min(info_s[i.first], info_key[i.first]);
		}
		return ans == info;
	};
	while (t--) {
		string s; int sz, ans = 0, start; pair<int, int> info;
		cin >> s >> info.first >> info.second;
		sz = (int) s.size();
		for (int i = pow(10, sz - 1); i < pow(10, sz); ++i) {
			string key = to_string(i);
			if (check(key, s, info)) {
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}