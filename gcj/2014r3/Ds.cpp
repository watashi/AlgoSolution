#include <bitset>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 80;
const int INF = 1'000'000'007;

int c[MAXN];
vector<int> e[MAXN];
bitset<MAXN> ebs[MAXN][MAXN], vbs[MAXN][MAXN];

void dfs(int v, int p, bitset<MAXN> ret[MAXN], bitset<MAXN> ret2[MAXN]) {
  if (p == -1) {
    ret[v].reset();
    ret2[v].reset();
    ret2[v].set(v);
  } else {
    ret[v] = ret[p];
    ret[v].set(min(v, p));
    ret2[v] = ret2[p];
    ret2[v].set(v);
  }
  for (int w: e[v]) {
    if (w != p) {
      dfs(w, v, ret, ret2);
    }
  }
}

inline bool good(const bitset<MAXN>& bs, int s, int t) {
  return !bs.test(min(s, t));
}

int gao(int sx, int tx, int sy, int ty) {
  // printf("%d %d %d %d\n", sx, tx, sy, ty);
  int ret = -INF;
  bool flag = false;
  for (int i: e[tx]) {
    if (good(ebs[sx][tx], tx, i) && good(ebs[sy][ty], tx, i)) {
      flag = true;
      ret = max(ret, (vbs[sy][ty].test(i) ? 0 : c[i]) - gao(sy, ty, sx, i));
    }
  }
  if (!flag) {
    for (int i: e[ty]) {
      if (good(ebs[sx][tx], ty, i) && good(ebs[sy][ty], ty, i)) {
        flag = true;
        break;
      }
    }
    return flag ? -gao(sy, ty, sx, tx) : 0;
  } else {
    return ret;
  }
}

int main() {
  int re, n, t;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &c[i]);
      e[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
      scanf("%d", &t);
      --t;
      e[i].emplace_back(t);
      e[t].emplace_back(i);
    }

    for (int i = 0; i < n; ++i) {
      dfs(i, -1, ebs[i], vbs[i]);
    }

    int besta = -INF;
    for (int i = 0; i < n; ++i) {
      int bestb = -INF;
      for (int j = 0; j < n; ++j) {
        bestb = max(bestb, (j == i ? 0 : c[j]) - gao(i, i, j, j));
      }
      // printf("%d %d\n", c[i], bestb);
      besta = max(besta, c[i] - bestb);
    }

    printf("Case #%d: %d\n", ri, besta);
    fflush(stdout);
  }

  return 0;
}
