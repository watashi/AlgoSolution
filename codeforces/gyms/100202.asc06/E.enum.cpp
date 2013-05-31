#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
  double x, y;

  Point() { }
  explicit Point(double a): x(cos(a)), y(sin(a)) { }
  Point(double x, double y): x(x), y(y) { }

  double abs() const { return hypot(x, y); }
  double arg() const { return atan2(y, x); }

  Point scale(double r) const { return Point(x * r, y * r); }
  Point trunc(double r) const { return scale(r / abs()); }

  Point operator-() const { return Point(-x, -y); }
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }

  double operator*(const Point& o) const { return x * o.x + y * o.y; }
  double operator%(const Point& o) const { return x * o.y - y * o.x; }

  Point proj(const Point& u) const { return Point(u * *this, u % *this); };
  Point rot(double a) const { return proj(Point(a)); }
};

const double EPS = 1e-8;
const double PI = acos(-1.0);

bool inside(int n, const Point p[], const Point& o) {
  for (int i = 0; i < n; ++i) {
    if ((p[(i + 1) % n] - p[i]) % (o - p[i]) < -EPS) {
      return false;
    }
  }
  return true;
}

bool inside(int n, const Point p[], int m, const Point q[]) {
  for (int i = 0; i < m; ++i) {
    if (!inside(n, p, q[i])) {
      return false;
    }
  }
  return true;
}

double frem(double a, double b) {
  double ret = fmod(a, b);
  while (ret < 0) {
    ret += b;
  }
  return ret;
}

bool solve(const Point& o, const Point& a, double r, Point& ret) {
  double d[2][2] = {
    {1 - r * a.x, r * a.y},
    {-r * a.y, 1 - r * a.x}
  };
  double det = d[0][0] * d[1][1] - d[0][1] * d[1][0];
  if (fabs(det) < EPS) {
    return false;
  } else {
    ret.x = (o.x * d[1][1] - d[0][1] * o.y) / det;
    ret.y = (d[0][0] * o.y - o.x * d[1][0]) / det;
    return true;
  }
}

int main() {
  Point p1[4], p2[4], p3[4], o2, u2, o3, u3, q;
  double s1, s2, s3, w, h;
  vector<double> v;

#ifndef __WATASHI__
  freopen("maps.in", "r", stdin);
  freopen("maps.out", "w", stdout);
#endif
  for (int i = 0; i <= 360; ++i) {
    v.push_back(PI * i / 180);
  }

  scanf("%lf%lf%lf%lf%lf", &s1, &w, &h, &s2, &s3);
  for (int i = 0; i < 4; ++i) {
    scanf("%lf%lf", &p3[i].x, &p3[i].y);
  }
  o3 = p3[0];
  u3 = (p3[1] - p3[0]).trunc(1.0);

  if (!solve(o3, u3, s3 / s1, q) ||
    q.x < -EPS ||
    q.x > w + EPS ||
    q.y < -EPS ||
    q.y > h + EPS) {
    puts("impossible");
    return 0;
  }

  p1[0] = Point(0, 0);
  p1[1] = Point(w, 0);
  p1[2] = Point(w, h);
  p1[3] = Point(0, h);

  for (int i = 0; i < 2 * (int)v.size() - 1; i += 2) {
    u2 = Point((v[i / 2] + v[(i + 1) / 2]) / 2).scale(s2 / s1);
    o2 = q - q.proj(u2);
    for (int j = 0; j < 4; ++j) {
      p2[j] = o2 + p1[j].proj(u2);
    }
    if (inside(4, p1, 4, p2) && inside(4, p2, 4, p3)) {
      for (int j = 0; j < 4; ++j) {
        printf("%.10lf %.10lf%c", p2[j].x, p2[j].y, j == 3 ? '\n' : ' ');
      }
      return 0;
    }
  }
  puts("impossible");
  return 0;
}

