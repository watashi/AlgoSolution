#include <bits/stdc++.h>

using namespace std;

static const string GRID = "./\\";
constexpr int LEFT = 1;
constexpr int RIGHT = 2;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int c;
    scanf("%d", &c);
    vector<int> b(c);
    for (int& i: b) {
      scanf("%d", &i);
    }

    printf("Case #%d: ", ri);
    if (b.front() == 0 || b.back() == 0) {
      puts("IMPOSSIBLE");
      continue;
    }

    map<int, map<int, int>> m;
    m[-1];
    for (int i = 0, s = 0; i < (int)b.size(); ++i) {
      if (b[i] == 0) {
        continue;
      }
      int t = s + b[i];
      for (int j = s; j < i; ++j) {
        m[j - s][j] = RIGHT;
      }
      for (int j = t - 1; j > i; --j) {
        m[t - 1 - j][j] = LEFT;
      }
      s = t;
    }

    int r = m.rbegin()->first + 2;
    printf("%d\n", r);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        auto k = m[i].find(j);
        putchar(GRID[k == m[i].end() ? 0 : k->second]);
      }
      puts("");
    }
  }

  return 0;
}
