// 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n, k; cin >> n >> k;
	vector<long long> sieve(n + 10, 0), primes, ans;
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] && (long long)i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
	for (int i = 0; i < n + 1; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}

	for (auto &prime : primes) {
		// cout << prime << ' ';
		for (int i = 1; ; ++i) {
			int aux = prime * i;
			if (aux > n + 10) {
				break;
			}
			++sieve[aux];
		}
	}
	if (k == 2) {
		for (int i = 1; i <= n; ++i) {
			if (sieve[i] == sieve[i + 1] && sieve[i] == 2) {
				ans.push_back(i);
			}
		}
	} else if (k == 3) {
		for (int i = 1; i <= n; ++i) {
			if (sieve[i] == sieve[i + 1] && sieve[i + 1] == sieve[i + 2] && sieve[i] == 3) {
				ans.push_back(i);
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			if (sieve[i] == sieve[i + 1] && sieve[i + 1] == sieve[i + 2] && sieve[i + 2] == sieve[i + 3] && sieve[i] == 4) {
				ans.push_back(i);
			}
		}
	}
	for (auto &x : ans) {
		cout << x << '\n';
	}
	return 0;
}