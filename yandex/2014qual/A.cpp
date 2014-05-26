#include <cstdio>
#include <algorithm>

const int MAXN = 512;

static int a[MAXN][MAXN];

int main() {
  int n, m, x, y, ans;

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  ans = -1;
  x = y = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int tmp = 7 * a[i][j];
      for (int ii = i - 1; ii <= i + 1; ++ii) {
        for (int jj = j - 1; jj <= j + 1; ++jj) {
          tmp += a[ii][jj];
        }
      }
      if (tmp > ans) {
        ans = tmp;
        x = i;
        y = j;
      }
    }
  }
  printf("%d %d\n", x, y);

  return 0;
}


