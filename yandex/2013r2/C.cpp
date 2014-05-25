#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 2048;
const double EPS = 1e-8;
const double PI = acos(-1.0);

struct Point {
  llint x, y;

  Point() { }

  Point(llint x, llint y): x(x), y(y) { }

  double arg() const {
    return atan2(y, x);
  }

  Point operator-(const Point& o) const {
    return Point(x - o.x, y - o.y);
  }

  llint operator*(const Point& o) const {
    return x * o.y - y * o.x;
  }

  bool operator<(const Point& o) const {
    return x != o.x ? x < o.x : y < o.y;
  }
} p[MAXN];

int main() {
  int n, m;
  llint sx, sy;
  double ans = 0.0;
  vector<pair<double, Point> > v;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
  }

  /*
  double cmp = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < j; ++k) {
        cmp += fabs((p[i] - p[j]) * (p[k] - p[j]));
      }
    }
  }
  cmp /= (double)(n * (n - 1LL) * (n - 2LL)) / 3.0;
  printf("%.12lf\n", cmp);
  */

  for (int k = 0; k < n; ++k) {
    v.clear();
    for (int i = k + 1; i < n; ++i) {
      Point t = p[i] - p[k];
      v.push_back({t.arg(), t});
    }
    sort(v.begin(), v.end());

    m = v.size();
    for (int i = 0; i < m; ++i) {
      v.push_back(v[i]);
      v.back().first += 2 * PI;
    }

    sx = 0;
    sy = 0;
    for (int i = 0, j = 0; i < m; ++i) {
      if (j <= i) {
        sx = 0;
        sy = 0;
        j = i + 1;
      } else {
        sx -= v[i].second.x;
        sy -= v[i].second.y;
      }
      while (j < i + m && v[i].second * v[j].second > 0) {
        sx += v[j].second.x;
        sy += v[j].second.y;
        ++j;
      }
      ans += (double)v[i].second.x * (double)sy - (double)v[i].second.y * (double)sx;
    }
  }
  printf("%.12lf\n", ans / n / (n - 1) / (n - 2) * 3);

  return 0;
}

