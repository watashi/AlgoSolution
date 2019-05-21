#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int a, x, y;

    scanf("%d", &a);
    x = 1;
    y = a;
    for (int i = 2; i * i <= a; ++i) {
      int j = (a + i - 1) / i;
      if (i + j <= x + y) {
        x = i;
        y = j;
      }
    }

    int mx = max(3, x);
    int my = max(3, y);
    vector<vector<bool>> m(mx, vector<bool>(my));

    while (true) {
      x = 1;
      y = 1;
      a = 0;
      for (int i = 1; i + 1 < mx; ++i) {
        for (int j = 1; j + 1 < my; ++j) {
          int k = 0;
          for (int ii = i - 1; ii <= i + 1; ++ii) {
            for (int jj = j - 1; jj <= j + 1; ++jj) {
              if (!m[ii][jj]) {
                ++k;
              }
            }
          }
          if (k > a ||
              (k == a &&
                abs(i * 2 - mx) + abs(j * 2 - my) < abs(x * 2 - mx) + abs(y * 2 - my))) {
            x = i;
            y = j;
            a = k;
          }
        }
      }
      printf("%d %d\n", 100 + x, 100 + y);
      fflush(stdout);
      scanf("%d%d", &x, &y);
      if (x == 0 && y == 0) {
        break;
      } else if (x == -1 && y == -1) {
        return 1;
      } else {
        m[x - 100][y - 100] = true;
      }
    }
  }

  return 0;
}
