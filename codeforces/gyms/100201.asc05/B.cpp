#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 128;

int main() {
  int n;
  bool blank = false;
  double s, a, ca, sa;
  double x[MAXN], y[MAXN];

#ifndef __WATASHI__
  freopen("angle.in", "r", stdin);
  freopen("angle.out", "w", stdout);
#endif
  while (scanf("%d", &n) != EOF && n > 0) {
    if (blank) {
      puts("");
    } else {
      blank = true;
    }

    s = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf", x + i, y + i);
      if (i > 0) {
        s = fmod(s + atan2(y[i] - y[i - 1], x[i] - x[i - 1]), 2 * PI);
      }
    }
    while (s < -EPS) {
      s += 2 * PI;	// !!WA!!
    }
    a = s < EPS ? 0 : (2 * PI - s) / (n - 1);
    printf("0\n%.16lf\n", a);
    ca = cos(a);
    sa = sin(a);
    for (int i = 0; i < n; ++i) {
      printf("%.16lf %.16lf\n", ca * x[i] - sa * y[i], sa * x[i] + ca * y[i]);
    }
  }

  return 0;
}

