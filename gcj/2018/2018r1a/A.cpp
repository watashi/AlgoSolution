#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXN = 200;
char buf[MAXN];
int s[MAXN][MAXN];

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int r, c, h, v;
    scanf("%d%d%d%d", &r, &c, &h, &v);
    ++h;
    ++v;
    fill(s[0], s[r + 1], 0);
    for (int i = 1; i <= r; ++i) {
      scanf("%s", buf);
      for (int j = 1; j <= c; ++j) {
        s[i][j] = s[i][j - 1];
        if (buf[j - 1] == '@') {
          ++s[i][j];
        }
      }
      for (int j = 1; j <= c; ++j) {
        s[i][j] += s[i - 1][j];
      }
    }

    bool possible = s[r][c] % (h * v) == 0;
    int dh = s[r][c] / h, dv = s[r][c] / v, d = s[r][c] / (h * v);
    vector<int> hs(h + 1, -1), vs(v + 1, -1);
    if (possible && d > 0) {
      for (int i = 0; i <= r; ++i) {
        if (s[i][c] % dh == 0) {
          hs[s[i][c] / dh] = i;
        }
      }
      for (int j = 0; j <= c; ++j) {
        if (s[r][j] % dv == 0) {
          vs[s[r][j] / dv] = j;
        }
      }
      possible = possible && find(hs.begin(), hs.end(), -1) == hs.end();
      possible = possible && find(vs.begin(), vs.end(), -1) == vs.end();
      for (int i = 0; i <= h && possible; ++i) {
        for (int j = 0; j <= v && possible; ++j) {
          possible = possible && i * j * d == s[hs[i]][vs[j]];
        }
      }
    }
    printf("Case #%d: %s\n", ri, possible ? "POSSIBLE" : "IMPOSSIBLE");
  }

  return 0;
}
