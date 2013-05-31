#include <cmath>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

struct Point {
  double x, y;

  Point() { }
  explicit Point(double a): x(cos(a)), y(sin(a)) { }
  Point(double x, double y): x(x), y(y) { }

  double abs2() const { return x * x + y * y; }
  double abs() const { return hypot(x, y); }
  double arg() const { return atan2(y, x); }

  Point scale(double r) const { return Point(x * r, y * r); }
  Point trunc(double r) const { return scale(r / abs()); }

  Point operator-() const { return Point(-x, -y); }
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }

  double operator*(const Point& o) const { return x * o.x + y * o.y; }
  double operator%(const Point& o) const { return x * o.y - y * o.x; }

  Point project(const Point& o) const {
    return Point(o * *this, o % *this).scale(1.0 / o.abs2());
  }

  Point transform(const Point& o) const {
    return Point(x * o.x - y * o.y, x * o.y + y * o.x);
  }
};

const double EPS = 1e-8;
const double PI = acos(-1.0);

bool intersection(const Point& a, const Point& b, const Point& o, double r,
    Point& p1, Point& p2) {
  Point u = (b - a).trunc(1.0), v = (o - a).project(u);
  if (fabs(v.y) > r + EPS) {
    return false;
  } else {
    double d = (r - v.y) * (r + v.y);
    d = sqrt(d <= 0 ? 0 : d);
    p1 = a + u.scale(v.x - d);
    p2 = a + u.scale(v.x + d);
    return true;
  }
}

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

vector<double> gao(int n, const Point p[], const Point& o, double r) {
  vector<double> ret;
  Point p1, p2;
  for (int i = 0; i < n; ++i) {
    if (intersection(p[i], p[(i + 1) % n], o, r, p1, p2)) {
      ret.push_back((p1 - o).arg());
      ret.push_back((p2 - o).arg());
    }
  }
  return ret;
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

void plot(int n, const Point p[], const char* style) {
  fprintf(stderr, "draw ");
  for (int i = 0; i < n; ++i) {
    fprintf(stderr, "(%lfu,%lfu)--", p[i].x, p[i].y);
  }
  fprintf(stderr, "cycle %s;\n", style);
  fprintf(stderr, "draw fullcircle scaled 3 shifted (%lfu,%lfu);\n", p[0].x, p[0].y);
}

int main() {
  int re;
  Point p1[4], p2[4], p3[4], u2, o3, u3, q;
  double s1, s2, s3, w, h;
  vector<double> v;

#ifdef __WATASHI__
  fprintf(stderr, "u=1in;\n\n");
#endif
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
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
      goto NEXT;
    }

    p1[0] = Point(0, 0);
    p1[1] = Point(w, 0);
    p1[2] = Point(w, h);
    p1[3] = Point(0, h);
#ifdef __WATASHI__
    // printf("Case #%d: ", ri);
    fprintf(stderr, "beginfig(%d);\n", ri);
    fprintf(stderr, "pickup pencircle scaled 5;\n");
    fprintf(stderr, "fill fullcircle scaled 25 shifted (%lfu,%lfu) withcolor green;\n", q.x, q.y);
    plot(4, p1, "withcolor red");
    plot(4, p3, "withcolor blue");
    fprintf(stderr, "pickup pencircle scaled 1;\n");
#endif

    v.clear();
    for (int i = 0; i < 4; ++i) {
      Point d = p1[i] - q;
      if (d.abs() < EPS) {
        continue;
      }

      vector<double> w1 = gao(4, p1, q, d.abs() * s2 / s1);
      for (int j = 0; j < (int)w1.size(); ++j) {
        v.push_back(frem(w1[j] - d.arg(), 2 * PI));
      }

      vector<double> w3 = gao(4, p1, q, d.abs() * s3 / s2);
      for (int j = 0; j < (int)w3.size(); ++j) {
        v.push_back(frem(u3.arg() - (w3[j] - d.arg()), 2 * PI));
      }
    }

    for (int i = 0; i < (int)v.size(); ++i) {
      u2 = Point(v[i]).scale(s2 / s1);
      for (int j = 0; j < 4; ++j) {
        p2[j] = q + (p1[j] - q).transform(u2);
      }
#ifdef __WATASHI__
      plot(4, p2, "");
#endif
      if (inside(4, p1, 4, p2) && inside(4, p2, 4, p3)) {
        for (int j = 0; j < 4; ++j) {
          printf("%.10lf %.10lf%c", p2[j].x, p2[j].y, j == 3 ? '\n' : ' ');
        }
#ifdef __WATASHI__
        plot(4, p2, "withcolor (1,0,1)");
        fprintf(stderr, "endfig;\n\n");
#endif
        goto NEXT;
      }
    }
#ifdef __WATASHI__
    fprintf(stderr, "endfig;\n\n");
#endif
    puts("impossible");
NEXT:
    continue;
  }
#ifdef __WATASHI__
  fprintf(stderr, "end\n");
#endif

  return 0;
}

