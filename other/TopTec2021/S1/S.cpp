// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n, tmp, a = 0, b = 0; cin >> n;
		vector<long long> nums(n);
		for (auto &x : nums) {
			cin >> x;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i) {
			long long val = nums[n - i - 1];
			// bob
			if (i & 1) {
				if (val & 1) {
					b += val;
				}
			} else {
				if (!(val & 1)) {
					a += val;
				}
			}
		}
		if (a > b) {
			cout << "Alice\n";
		} else if (a == b) {
			cout << "Tie\n";
		} else {
			cout << "Bob\n";
		}
	}
	return 0;
}
// // 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);	cout.tie(0);
// 	int t; cin >> t;
// 	while (t--) {
// 		long long n, tmp, a = 0, b = 0; cin >> n;
// 		priority_queue<long long> odd, even;
// 		for (int i = 0; i < n; ++i) {
// 			cin >> tmp;
// 			if (tmp & 1) {
// 				odd.push(tmp);
// 			} else {
// 				even.push(tmp);
// 			}
// 		}
// 		for (int i = 0; i < n; ++i) {
// 			long long diff, e = -1, o = -1;
// 			if (!even.empty()) {
// 				e = even.top();
// 			}
// 			if (!odd.empty()) {
// 				o = odd.top();
// 			}
// 			// bob
// 			if (i & 1) {
// 				diff = o - e;
// 				if (diff > 0) {
// 					b += o;
// 					odd.pop();
// 				} else {
// 					even.pop();
// 				}
// 			} else {
// 				// alice
// 				diff = e - o;
// 				if (diff > 0) {
// 					a += e;
// 					even.pop();
// 				} else {
// 					odd.pop();
// 				}
// 			}
// 		}
// 		if (a > b) {
// 			cout << "Alice\n";
// 		} else if (a == b) {
// 			cout << "Tie\n";
// 		} else {
// 			cout << "Bob\n";
// 		}
// 	}
// 	return 0;
// }