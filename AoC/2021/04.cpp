// https://adventofcode.com/2021/day/4
#include <bits/stdc++.h>
using namespace std;

struct bingo {
  size_t n;
  int non_selected;
  bool finished;
  map<int, pair<int, int>> board;
  vector<int> rows, columns;
  bingo() : non_selected(0), n(5), finished(false) {
    board.clear();
    rows.assign(n, 0);
    columns.assign(n, 0);
  }
  size_t size() { return n; }
  bool add(int num) {
    if (board.find(num) == board.end()) {
      return false;
    }
    int &i = board[num].first, &j = board[num].second;
    ++rows[i];
    ++columns[j];
    non_selected -= num;
    if (rows[i] == n || columns[j] == n) {
      finished = true;
      return true;
    }
    return false;
  }
  // pair<int, int> operator[](int idx) const { return board[idx]; }
  pair<int, int>& operator[](int idx) { return board[idx]; }
};

std::istream& operator>>(std::istream& stream, bingo& b) {
  int n = (int) b.size(), read;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      stream >> read;
      b[read] = {i, j};
      b.non_selected += read;
    }
  }
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const bingo &b) {
  for (auto &x : b.board) {
    stream << x.first << ' ';
  }
  stream << '\n';
  return stream;
}

void first() {
  vector<int> v;
  string s;
  int read = -1, n, card, non_selected;
  getline(cin, s);
  while (read != stoi(s)) {
    read = stoi(s);
    v.push_back(read);
    s = s.substr(s.find(',')+1);
  }
  n = (int) v.size();
  vector<bingo> f;
  bingo aux;
  bool game_over = false;
  while (cin >> aux) {
    f.push_back(aux);
    aux = bingo();
  }
  for (int i = 0; i < n && !game_over; ++i) {
    for (int j = 0; j < (int) f.size(); ++j) {
      if (f[j].add(v[i])) {
        game_over = true;
        card = v[i];
        non_selected = f[j].non_selected;
        break;
      }
    }
  }
  cout << card * non_selected << '\n';
}

void second() {
  vector<int> v;
  string s;
  int read = -1, n, card, non_selected, cnt = 0;
  getline(cin, s);
  while (read != stoi(s)) {
    read = stoi(s);
    v.push_back(read);
    s = s.substr(s.find(',')+1);
  }
  n = (int) v.size();
  vector<bingo> f;
  bingo aux;
  while (cin >> aux) {
    f.push_back(aux);
    aux = bingo();
  }
  for (int i = 0; i < n && cnt != (int) f.size(); ++i) {
    for (int j = 0; j < (int) f.size(); ++j) {
      if (!f[j].finished && f[j].add(v[i])) {
        ++cnt;
        card = v[i];
        non_selected = f[j].non_selected;
      }
    }
  }
  cout << card * non_selected << '\n';
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);  cout.tie(0);
  freopen("i.txt", "r", stdin);
  if (argc == 1) {
    first();
  } else {
    second();
  }
  return 0;
}
