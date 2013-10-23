#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int BEST_LIMIT = 10;
const double EPS = 1e-4;
const double RADIUS = 1;

#define GAO(a) do {\
  cirs.push_back(a);\
  gao();\
  cirs.pop_back();\
} while (false)

inline double sqr(double x) {
  return x * x;
}

struct Point {
  double x, y;
  Point() { }
  Point(double x, double y) : x(x), y(y) { }
// Point(const Point& p) : x(p.x), y(p.y) { }
// Point& operator=(const Point& p) { x = p.x; y = p.y; return *this; }
};

#include <string>

string sit(const Point& s) {
  static char buf[80];
  sprintf(buf, "(%lf, %lf)", s.x, s.y);
  return buf;
}

#define S(x) sit(x).c_str()

inline bool operator<(const Point& a, const Point& b) {
  return a.x < b.x - EPS || (a.x < b.x + EPS && a.y < b.y - EPS);
}

inline Point operator+(const Point& a, const Point& b) {
  return Point(a.x + b.x, a.y + b.y);
}

inline Point operator-(const Point& a, const Point& b) {
  return Point(a.x - b.x, a.y - b.y);
}

inline Point operator*(const double& a, const Point& b) {
  return Point(a * b.x, a * b.y);
}

inline double operator%(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

inline Point unit(const Point& p) {
  double l = hypot(p.x, p.y);
  return 1 / l * p;
}

inline double xmult(const Point& a, const Point& b, const Point& p) {
  return (b - a) % (p - a);
}

inline bool inside(int n, const Point a[], const Point& p) {
  for (int i = 0; i < n; ++i) {
    if (xmult(a[i], a[i + 1], p) < -EPS) {
      return false;
    }
  }
  return true;
}

inline bool gaocircir(const Point& a, const Point& b, Point& ret) {
  Point d = b - a;
  double dd = hypot(d.x, d.y) / 2;
  if (dd > 2 * RADIUS + EPS) {
    return false;
  }
  Point e(-d.y, d.x);
  double ee = sqrt(fabs(sqr(2 * RADIUS) - sqr(dd))) / hypot(e.x, e.y);
  ret = 0.5 * (a + b) + ee * e;
  return true;
}

inline bool gaociredg(const Point& a, const Point& b, const Point& c, Point& ret1, Point& ret2) {
  Point ab = unit(b - a);
  double dd = ab % (c - a) - RADIUS;
  // assert(dd > -EPS)
  if (dd > 2 * RADIUS + EPS) {
    return false;
  }
  // Point e = 0.5 * (a + b) + Point(-ab.y, ab.x); // zhua!!
  Point e = c - dd * Point(-ab.y, ab.x);
  double ee = sqrt(fabs(sqr(2 * RADIUS) - sqr(dd)));
  ret1 = e + ee * ab;
  ret2 = e - ee * ab;
  return true;
}

inline bool gaoedgedg(const Point& a, const Point& b, const Point& c, Point& ret) {
// printf("arg %s %s %s\n", S(a), S(b), S(c));
  Point ab = unit(b - a), ac = unit(c - a), ad = unit(ab + ac);
// printf("in %s %s %s\n", S(ab), S(ac), S(ad));
  double d = 1 / (ac % ad);
  ret = a + d * ad;
// printf("out %lf %s\n", d, S(ret));
  return true;
}

Point p[6], w1[3], w2[3];
set<vector<Point> > svp;
vector<Point> cirs, cirsbest;
int best;

inline bool ok(const Point& p) {
  bool ret = true;
  for (int i = 0; ret && i < 3; ++i) {
    ret &= xmult(w1[i], w2[i], p) >= -EPS;
  }
  for (int i = 0; ret && i < (int)cirs.size(); ++i) {
    ret &= sqr(p.x - cirs[i].x) + sqr(p.y - cirs[i].y) >= sqr(2 * RADIUS - EPS);
  }
  return ret;
}

void gao() {
  {
    vector<Point> vp(cirs);
    sort(vp.begin(), vp.end());
    if (svp.count(vp) > 0) {
      return;
    } else {
      svp.insert(vp);
    }
    if (best < (int)vp.size()) {
      best = (int)vp.size();
      cirsbest = vp;
      if (best == BEST_LIMIT) {
        throw 1;
      }
    }
  }

  Point a, b;

  for (int i = 1; i <= 3; ++i) {
    if (gaoedgedg(p[i], p[i - 1], p[i + 1], a) && ok(a)) {
      GAO(a);
    }
  }

  for (int i = 0; i < (int)cirs.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      if (gaociredg(p[j], p[j + 1], cirs[i], a, b)) {
        if (ok(a)) {
          GAO(a);
        }
        if (ok(b)) {
          GAO(b);
        }
      }
    }

    for (int j = 0; j < (int)cirs.size(); ++j) {
      if (i != j && gaocircir(cirs[i], cirs[j], a) && ok(a)) {
        GAO(a);
      }
    }
  }
}

int ans[11][11][11];

int gao(int a, int b, int c) {
  double d = (sqr(b) - sqr(a)) / c;
  p[0].y = p[1].y = 0;
  p[0].x = -(c - d) / 2;
  p[1].x = (c + d) / 2;
  p[2].x = 0;
  p[2].y = sqrt(sqr(b) - sqr(p[1].x));
  for (int i = 0; i < 3; ++i) {
    p[3 + i] = p[i];
  }
  for (int i = 0; i < 3; ++i) {
    Point q = unit(p[i + 1] - p[i]);
    q = Point(-q.y, q.x);
    w1[i] = p[i] + q;
    w2[i] = p[i + 1] + q;
  }
  //printf("%s %s %s\n", S(p[0]), S(p[1]), S(p[2]));
  //printf("%s %s\n", S(w1[0]), S(w2[0]));
  //printf("%s %s\n", S(w1[1]), S(w2[1]));
  //printf("%s %s\n", S(w1[2]), S(w2[2]));

  best = 0;
  svp.clear();
  cirs.clear();

  try {
    gao();
  } catch (...) {
  }
  return best;
}

void debug() {
  int a[3];

  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  sort(a, a + 3);
  gao(a[0], a[1], a[2]);
  printf("u=1cm;\nbeginfig(%d%d%d)\n\tdraw (%lfu,%lfu)--(%lfu,%lfu)--(%lfu,%lfu)--cycle;\n",
    a[0] % 10, a[1] % 10, a[2] % 10, p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
  for (int i = 0; i < (int)cirsbest.size(); ++i) {
    printf("\tdraw fullcircle scaled 2u shifted (%lfu, %lfu);\n", cirsbest[i].x, cirsbest[i].y);
  }
  for (int i = 0; i < 3; ++i) {
    printf("\tdraw (%lfu, %lfu)--(%lfu, %lfu);\n", w1[i].x, w1[i].y, w2[i].x, w2[i].y);
  }
  puts("\tdraw (0,-2u)--(0,8u);\n");
  puts("\tdraw fullcircle scaled 2u shifted (0, -2u)\nendfig");
  exit(0);
}

int main() {
  int n, a[3];

  // debug();
  for (int a = 1; a <= 10; ++a) {
    for (int b = a; b <= 10; ++b) {
      for (int c = b; c <= 10; ++c) {
        if (a + b > c) {
          ans[a][b][c] = gao(a, b, c);
          // printf("%d %d %d: %d\n", a, b, c, ans[a][b][c]);
        }
      }
    }
  }

#ifndef __WATASHI__
  freopen("newyear.in", "r", stdin);
  freopen("newyear.out", "w", stdout);
#endif
  scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
  sort(a, a + 3);
  printf("%d\n", min(n, ans[a[0]][a[1]][a[2]]));

  return 0;
}

