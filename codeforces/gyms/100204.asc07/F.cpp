#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

struct Point {
  double x, y;
  Point() { };
  Point(double x, double y) : x(x), y(y) { }
};

inline double sqr(double x) { return x * x; }

void gao(const Point& u, const Point& v, double r, vector<Point>& ret) {
  double a = sqr(v.x - u.x) + sqr(v.y - u.y);
  double b = 2 * ((v.x - u.x) * u.x + (v.y - u.y) * u.y);
  double c = sqr(u.x) + sqr(u.y) - r * r;
  // printf("%lf %lf %lf\n", a, b, c);
  double d = b * b - 4 * a * c;
  ret.push_back(u);
  if (d < 0) {
    return;
  }
  d = sqrt(d);
  double t1 = (-b + d) / (2 * a);
  double t2 = (-b - d) / (2 * a);
  if (t1 > t2) {
    swap(t1, t2);
  }
  // printf("(%.3lf, %.3lf)\n", t1, t2);
  if (t1 > EPS && t1 < 1 - EPS) {
    ret.push_back(Point(u.x + (v.x - u.x) * t1, u.y + (v.y - u.y) * t1));
  }
  if (t2 > EPS && t2 < 1 - EPS && t2 - t1 > EPS) {
    ret.push_back(Point(u.x + (v.x - u.x) * t2, u.y + (v.y - u.y) * t2));
  }
}

double tri(const Point& u, const Point& v) {
  return u.x * v.y - u.y * v.x;
}

double arc(const Point& u, const Point& v, double r) {
  double t = atan2(v.y, v.x) - atan2(u.y, u.x);
  while (t > PI) {  // WA!!
    t -= 2 * PI;
  }
  while (t < -PI) {
    t += 2 * PI;
  }
  return r * r * t;
}

int main() {
  bool blank = false;
  double x, y, r, x1, y1, x2, y2, ans;

#ifndef __WATASHI__
  freopen("mammoth.in", "r", stdin);
  freopen("mammoth.out", "w", stdout);
#endif
  scanf("%lf%lf%lf", &x, &y, &r);
  scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
  x1 -= x;
  y1 -= y;
  x2 -= x;
  y2 -= y;
  if (blank) {
    puts("");
  } else {
    blank = true;
  }

  vector<Point> v;
  gao(Point(x1, y1), Point(x1, y2), r, v);
  gao(Point(x1, y2), Point(x2, y2), r, v);
  gao(Point(x2, y2), Point(x2, y1), r, v);
  gao(Point(x2, y1), Point(x1, y1), r, v);

  ans = 0;
  v.push_back(v.front());
  for (int i = 1; i < (int)v.size(); ++i) {
    // printf("%.3lf %.3lf: %.4lf\n", v[i].x, v[i].y, ans);
    if (hypot((v[i - 1].x + v[i].x) / 2, (v[i - 1].y + v[i].y) / 2) < r) {
      ans += tri(v[i - 1], v[i]);
    } else {
      ans += arc(v[i - 1], v[i], r);
    }
  }
  printf("%.10lf\n", fabs(ans) / 2);

  return 0;
}


