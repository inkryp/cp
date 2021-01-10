// https://onlinejudge.org/external/2/255.pdf
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	int k_pos, q_pos, qp_pos;
	auto convert = [&] (int pos) {
		return make_pair(pos / 8, pos % 8);
	};
	auto notHorVer = [&] (pair<int, int> cur, pair<int, int> prime) {
		return cur.first != prime.first && cur.second != prime.second;
	};
	auto kingBetween = [&] (pair<int, int> k, pair<int, int> q, pair<int, int> qp) {
		if (k.first == q.first == qp.first) {
			return q.second <= k.second && k.second <= qp.second;
		} else if (k.second == q.second == qp.second) {
			return q.first <= k.first && k.first <= qp.first;
		}
		return false;
	};
	auto nextToEachOther = [&] (pair<int, int> k, pair<int, int> qp) {
		return abs(k.first - qp.first) == 1 || abs(k.second - qp.second) == 1;
	};
	auto stop = [&] (pair<int, int> k, pair<int, int> qp) {
		return (k.first == 0 || k.first == 7 || k.second == 0 || k.second == 7)
		&& abs(k.first - qp.second) == 1 && abs(k.second - qp.first) == 1;
	};
	while (cin >> k_pos >> q_pos >> qp_pos) {
		auto k = convert(k_pos), q = convert(q_pos), qp = convert(qp_pos);
		if (k == q) {
			cout << "Illegal state\n";
		} else if (notHorVer(q, qp) || kingBetween(k, q, qp)) {
			cout << notHorVer(q, qp) << ' ' << kingBetween(k, q, qp) << ' ';
			cout << "Illegal move\n";
		} else if (nextToEachOther(k, qp)) {
			cout << "Move not allowed\n";
		} else if (stop(k, qp)) {
			cout << "Stop\n";
		} else {
			cout << "Continue\n";
		}
	}
	return 0;
}