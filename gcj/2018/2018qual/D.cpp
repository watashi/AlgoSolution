#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

// https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula

void rotate110(long double x, long double y, long double z, long double si) {
  static constexpr long double k = 1 / sqrtl(2.0);  // (k, k, 0)
  long double co = sqrtl(1 - si * si);
  // printf("[%.6Lf %.6Lf %.6Lf]\n", si, co, sqrtl(2.0) * si + co);
  long double dot = k * k * (x + y) * (1 - co);
  long double xx = x * co + (k * z - 0) * si + dot;
  long double yy = y * co + (0 - k * z) * si + dot;
  long double zz = z * co + k * (y - x) * si;
  // printf("%.10lf\n", xx * xx + yy * yy + zz * zz);
  printf("%.20Lf %.20Lf %.20Lf\n", xx, zz, yy);
}

// sqrt(2) * sin(x) + cos(x) = a

int main() {
  int re;

  cin >> re;
  for (int ri = 1; ri <= re; ++ri) {
    long double s, a, b, d, x;

    cin >> s;
    a = 3;
    b = -2 * sqrtl(2) * s;
    d = max<long double>(1e-200, 12 - 4 * s * s);
    x = (-b - sqrtl(d)) / (2 * a);
    printf("Case #%d:\n", ri);
    rotate110(0.5, 0.0, 0.0, x);
    rotate110(0.0, 0.5, 0.0, x);
    rotate110(0.0, 0.0, 0.5, x);
    /*
    rotate110(+0.5, +0.5, +0.5, x);
    rotate110(+0.5, +0.5, -0.5, x);
    rotate110(+0.5, -0.5, +0.5, x);
    rotate110(+0.5, -0.5, -0.5, x);
    rotate110(-0.5, +0.5, +0.5, x);
    rotate110(-0.5, +0.5, -0.5, x);
    rotate110(-0.5, -0.5, +0.5, x);
    rotate110(-0.5, -0.5, -0.5, x);
    */
  }

  return 0;
}
