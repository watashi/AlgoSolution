#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

double b1, t1, b2, t2, l, ds, df, g;

// xy = gs/2
// def r = y/x
// b <= y(d/x)-g/2(d/x)^2 <= t
// rd-gd^2/2/(gs/2/r) = rd(1-d/s)
// b <= rd(1-d/s) <= t
double getSpeed(double d, double s, double b, double t) {
  double c = d * (1 - d / s);
  b /= c;
  t /= c;
  if (b > 1) {
    return sqrt(g * s / 2 * (b + 1 / b));
  } else if (t < 1) {
    return sqrt(g * s / 2 * (t + 1 / t));
  } else {
    return sqrt(g * s);
  }
}

double getSpeed(double s) {
  return max(getSpeed(ds, ds + s, b1, t1), getSpeed(df, df + l - s, b2, t2));
}

int main() {
  double lowerBound, upperBound, u, v;

  freopen("jumper.in", "r", stdin);
  freopen("jumper.out", "w", stdout);
  while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &b1, &t1, &b2, &t2, &l, &ds, &df, &g) != EOF) {
    lowerBound = 0;
    upperBound = l;
    for (int i = 0; i < 200; ++i) {	// while (upperBound - lowerBound > 1e-8) => WA
      u = (2 * lowerBound + upperBound) / 3;
      v = (lowerBound + 2 * upperBound) / 3;
      if (getSpeed(u) < getSpeed(v)) {
        upperBound = v;
      } else {
        lowerBound = u;
      }
    }
    printf("%.6lf\n", getSpeed((lowerBound + upperBound) / 2));
  }

  return 0;
}

