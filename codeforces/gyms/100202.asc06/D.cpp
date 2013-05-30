#include <cmath>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

const double EPS = 1e-10;

void solve3(double ac, double ad, double bc, double bd,
    double& ans, double& a, double& b, double& c, double& d) {
  double bd2 = ad * bc / ac;
  if (bd2 + EPS >= bd) {
    double ans2 = ac + ad + bc + bd2;
    if (ans2 < ans) {
      ans = ans2;
      a = 1;
      c = ac / a;
      d = ad / a;
      b = bc / c;
    }
  }
}

void solve2(double ac, double bd, double bc, double ad,
    double& ans, double& a, double& b, double& c, double& d) {
  double kl = bc / ac;
  double kr = bd / ad;
  double km = sqrt(bd / ac);
  if (kr - kl > -EPS) {
    if (km < kl) {
      km = kl;
    }
    if (km > kr) {
      km = kr;
    }
    a = 1;
    b = km;
    c = ac / a;
    d = bd / b;
    ans = (a + b) * (c + d);
  }
}

int main() {
  double ac, ad, bc, bd;
  static double ans, a, b, c, d;

#ifndef __WATASHI__
  freopen("lab.in", "r", stdin);
  freopen("lab.out", "w", stdout);
#endif
  while (scanf("%lf%lf%lf%lf", &ac, &ad, &bc, &bd) != EOF) {
    ans = numeric_limits<double>::max();
    solve3(bd, bc, ad, ac, ans, b, a, d, c);
    solve3(bc, bd, ac, ad, ans, b, a, c, d);
    solve3(ad, ac, bd, bc, ans, a, b, d, c);
    solve3(ac, ad, bc, bd, ans, a, b, c, d);
    solve2(ac, bd, bc, ad, ans, a, b, c, d);
    solve2(bc, ad, ac, bd, ans, b, a, c, d);
    printf("%.10lf\n%.10lf %.10lf %.10lf %.10lf\n", ans, a, b, c, d);
  }

  return 0;
}


