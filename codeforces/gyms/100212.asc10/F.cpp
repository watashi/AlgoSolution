#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#ifndef M_PI
const double M_PI = acos(-1.0);
#endif

// a in range [-2Pi, 2Pi] !!
// to [0, 2Pi]
inline double tostd(double a) {
  if (a < 0) {
    a += 2 * M_PI;
  }
  return a;
}

inline double diff(double a, double b) {
  double d = fabs(a - b);	// [0, 2Pi]
  if (d > M_PI) {
    d = 2 * M_PI - d;
  }
  return d;
}

double gao(const vector<pair<double, int> >& a, const vector<pair<double, int> >& b,
  vector<int>& ab, double h) {
  int n = a.size(), k = -1;
  double ret = numeric_limits<double>::max();
  for (int i = 0; i < n; ++i) {
    double tmp = 0;
    for (int j = 0; j < n; ++j) {
      tmp += hypot(diff(a[j].first, b[(j + i) % n].first), h);
    }
    if (ret > tmp) {
      ret = tmp;
      k = i;
    }
  }
  for (int j = 0; j < n; ++j) {
    ab[a[j].second] = b[(j + k) % n].second;
  }
  return ret;
}

int main() {
  int n;
  double r, h, ans;
  vector<pair<double, int> > a, b;
  vector<int> ab, ba;

#ifndef __WATASHI__
  freopen("magic.in", "r", stdin);
  freopen("magic.out", "w", stdout);
#endif
  scanf("%d%lf%lf", &n, &r, &h);
  a.resize(n);
  b.resize(n);
  ab.resize(n);
  ba.resize(n);
  ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &a[i].first);
    a[i].first = tostd(a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &b[i].first);
    b[i].first = tostd(b[i].first);
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  ans += gao(a, b, ab, h / 2 / r);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &a[i].first);
    a[i].first = tostd(a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  ans += gao(b, a, ba, h / 2 / r);
  ans *= r;
  printf("%.4lf\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d %d %d\n", i + 1, ab[i] + 1, ba[ab[i]] + 1);
  }

  return 0;
}
