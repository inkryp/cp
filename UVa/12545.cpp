// https://onlinejudge.org/external/125/12545.pdf
#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	// freopen("e.txt", "w", stderr);
	int amountCases; cin >> amountCases;
	for (int tc = 1; tc <= amountCases; ++tc) {
		cout << "Case " << tc << ": ";
		string s, t; cin >> s >> t;
		int os = 0, ot = 0, ans = 0;
		for (int i = 0; i < (int) s.size();) {
			if (s[i] == t[i]) {
				s.erase(s.begin() + i);
				t.erase(t.begin() + i);
			} else {
				++i;
			}
		}
		for (int i = 0; i < (int) s.size(); ++i) {
			switch (s[i]) {
				case '1':
					++os;
			}
			switch (t[i]) {
				case '1':
					++ot;
			}
		}
		debug(tc, s, os, t, ot, ans);
		// os + q + (s.size() - os - q) == ot + (t.size() - ot)
		if (os > ot) {
			ans = -1;
		} else {
			for (int i = 0; i < (int) s.size();) {
				if (os == ot) {
					break;
				}
				if (s[i] == '?' && t[i] == '1') {
					++ans;
					s.erase(s.begin() + i);
					t.erase(t.begin() + i);
					--ot;
				} else {
					++i;
				}
			}
			debug(tc, s, os, t, ot, ans);
			for (int i = 0; i < (int) s.size();) {
				if (s[i] == '?') {
					++ans;
					if (os == ot && t[i] == '0') {
						s.erase(s.begin() + i);
						t.erase(t.begin() + i);
					} else if (os == ot) {
						++i;
					} else {
						++os;
						++i;
					}
				} else {
					++i;
				}
			}
			int n = (int) s.size();
			debug(tc, s, os, t, ot, ans, (int)ceil(n / 2.0));
			if (os != ot) {
				n -= abs(os - ot);
				ans += abs(os - ot);
			}
			ans += ceil(n / 2.0);
		}
		cout << ans << endl;
	}
	return 0;
}