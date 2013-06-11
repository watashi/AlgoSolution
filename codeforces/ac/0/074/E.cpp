#include <map>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 6;

char a[MAXN][MAXN], b[MAXN];

int dis() {
  int ret = 0;
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      ret += abs(i - a[i][j] / MAXN);
      ret += abs(j - a[i][j] % MAXN);
    }
  }
  return ret;
}

void locate(int& x, int& y, int z) {
  for (x = 0; x < MAXN; ++x) {
    for (y = 0; y < MAXN; ++y) {
      if (a[x][y] == z) {
        return;
      }
    }
  }
}

void dump(const char* caption = "") {
#ifdef __WATASHI__
  printf("dump(%s)\n", caption);
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      printf(" %c%c", 'A' + a[i][j] / MAXN, '0' + a[i][j] % MAXN);
    }
    puts("");
  }
#endif
}

vector<tuple<char, int, int> > op;

void addop(char c, int i, int n) {
  op.push_back(tuple<char, int, int>(c, i, n));
#ifdef __WATASHI__
  static char buf[80];
  sprintf(buf, "<%c%d * %d>", c, i, n);
  dump(buf);
#endif
}

template<bool ADDOP = true>
void rotr(int x, int k) {
  k = (k % MAXN + MAXN) % MAXN;
  for (int i = 0; i < MAXN; ++i) {
    b[i] = a[x][i];
  }
  rotate(b, b + k, b + MAXN);
  for (int i = 0; i < MAXN; ++i) {
    a[x][i] = b[i];
  }
  if (ADDOP) {
    addop('L', x, k);
  }
}

template<bool ADDOP = true>
void rotc(int y, int k) {
  k = (k % MAXN + MAXN) % MAXN;
  for (int i = 0; i < MAXN; ++i) {
    b[i] = a[i][y];
  }
  rotate(b, b + k, b + MAXN);
  for (int i = 0; i < MAXN; ++i) {
    a[i][y] = b[i];
  }
  if (ADDOP) {
    addop('U', y, k);
  }
}

int main() {
  char ch;
  int x, y;

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      scanf(" %c", &ch);
      a[i][j] = (char)(isdigit(ch) ? ch - '0' : ch - 'A' + 10);
    }
  }
  dump();

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 1; j < MAXN; ++j) {
      locate(x, y, i * MAXN + j);
      rotr(x, y);
      rotc(0, x);
      if (x != 0) {
        rotr(x, -y);
      }
      rotr(i, j);
      rotc(0, -i);
      rotr(i, -j);
    }
  }

  for (int j = 0; j < MAXN; ++j) {
    locate(x, y, j);
    rotr(x, y);
    rotc(0, x - 1);
    rotr(x, -y);
    rotc(0, 1);
    rotr(0, 1);
  }

  priority_queue<pair<int, string> > todo;
  map<string, pair<char, int> > done;
  string src(a[0], a[MAXN]), trg(a[0], a[MAXN]);

  sort(trg.begin(), trg.end());
  done[src] = {'!', -1};
  todo.push({0, src});
  while (done.count(trg) == 0) {
    string cur = todo.top().second;
    todo.pop();
    copy(cur.begin(), cur.end(), a[0]);
#ifdef __WATASHI__
    string tmp = "";
    for (char i: cur) {
      tmp += (char)(i < 10 ? '0' + i : 'A' + (i - 10));
    }
    printf("%d %s\n", dis(), tmp.c_str());
#endif
    for (int i = 0; i < 1; ++i) { // use only first row and first col
      for (int j = 0; j < 4; ++j) {
        (j < 2 ? rotr<false> : rotc<false>)(i, j % 2 == 0 ? 1 : -1);
        cur = string(a[0], a[MAXN]);
        if (done.count(cur) == 0) {
          todo.push({-dis(), cur});
          done[cur] = {"LRUD"[j], i};
        }
        (j < 2 ? rotr<false> : rotc<false>)(i, j % 2 == 0 ? -1 : 1);
      }
    }
  }

  vector<pair<char, int> > tail;

  while (trg != src) {
    pair<char, int> by = done[trg];
    copy(trg.begin(), trg.end(), a[0]);
    tail.push_back(by);
    (by.first == 'L' || by.first == 'R' ? rotr<false> : rotc<false>)(
      by.second, by.first == 'L' || by.first == 'U' ? -1 : 1);
    trg = string(a[0], a[MAXN]);
  }
  reverse(tail.begin(), tail.end());
  for (const auto& i: tail) {
    addop(i.first, i.second, 1);
  }

  int ans = 0;

  for (const auto& i: op) {
    ans += get<2>(i);
  }
  printf("%d\n", ans);
  for (const auto& i: op) {
    char c;
    int p, q;
    tie(c, p, q) = i;
    for (int j = 0; j < q; ++j) {
      printf("%c%d\n", c, p + 1);
    }
  }

  return 0;
}
