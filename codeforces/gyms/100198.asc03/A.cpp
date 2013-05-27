#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

#ifndef M_PI
const double M_PI = acos(-1.0);
#endif

struct Point {
  double x, y;
};

bool operator<(const Point& lhs, const Point& rhs) {
  if (fabs(lhs.x - rhs.x) > EPS) {
    return lhs.x < rhs.x;
  } else if (fabs(lhs.y - rhs.y) > EPS) {
    return lhs.y < rhs.y;
  } else {
    return false;
  }
}

bool operator==(const Point& lhs, const Point& rhs) {
  return fabs(lhs.x - rhs.x) < EPS && fabs(lhs.y - rhs.y) < EPS;
}

struct Line {
  Point a, b;
};

bool parallel(const Line& lhs, const Line& rhs) {
  return fabs((lhs.a.x - lhs.b.x) * (rhs.a.y - rhs.b.y) - (lhs.a.y - lhs.b.y) * (rhs.a.x - rhs.b.x)) < EPS;
}

Point intesection(const Line& lhs, const Line& rhs) {
  Point ret = lhs.a;
  double r =
    ((lhs.a.x - rhs.a.x) * (rhs.a.y - rhs.b.y) - (lhs.a.y - rhs.a.y) * (rhs.a.x - rhs.b.x)) /
    ((lhs.a.x - lhs.b.x) * (rhs.a.y - rhs.b.y) - (lhs.a.y - lhs.b.y) * (rhs.a.x - rhs.b.x));
  ret.x += (lhs.b.x - lhs.a.x) * r;
  ret.y += (lhs.b.y - lhs.a.y) * r;
  return ret;
}

struct Edge {
  double a;
  int p;
  bool m;
  Edge(double a, int p) : a(a), p(p), m(false) {
  }
};

struct CmpA {
  bool operator()(const Edge& lhs, const Edge& rhs) const {
    return lhs.a < rhs.a;
  }
};

int search(const vector<Edge>& v, double a) {
  int l, r, m;
  double d;
  d = a + M_PI - EPS;
  if (d >= M_PI) {
    d -= 2 * M_PI;
  }
  l = 0;
  r = v.size();
  while (l < r) {
    m = (l + r) / 2;
    if (v[m].a < d) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  if (r == 0) {
    r = v.size() - 1;
  } else {
    --r;
  }
  d = v[r].a - a;
  if (d < 0) {
    d += 2 * M_PI;
  }
  if (d > M_PI - EPS) {
    return -1;
  } else {
    return r;
  }
}

const int MAXN = 81;

Line l[MAXN];
vector<Point> p[MAXN], vp;
map<Point, int> mp;
vector<Edge> e[MAXN * MAXN / 2];
vector<double> ans;

int main() {
  int n, m, a, b, c;
  double s;

  freopen("areas.in", "r", stdin);
  freopen("areas.out", "w", stdout);
  scanf("%d", &n);
  mp.clear();
  vp.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf%lf%lf", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
    p[i].clear();
    for (int j = 0; j < i; ++j) {
      if (!parallel(l[i], l[j])) {
        Point pt = intesection(l[i], l[j]);
        mp[pt];
        p[i].push_back(pt);
        p[j].push_back(pt);
      }
    }
  }
  m = 0;
  for (map<Point, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    vp.push_back(it->first);
    it->second = m;
    e[m].clear();
    ++m;
  }
  for (int i = 0; i < n; ++i) {
    if (p[i].size() < 2) {
      continue;
    }
    sort(p[i].begin(), p[i].end());
    p[i].erase(unique(p[i].begin(), p[i].end()), p[i].end());
    double ab = atan2(p[i].back().y - p[i].front().y, p[i].back().x - p[i].front().x);
    double ba = atan2(p[i].front().y - p[i].back().y, p[i].front().x - p[i].back().x);
    for (size_t j = 1; j < p[i].size(); ++j) {
      a = mp[p[i][j - 1]];
      b = mp[p[i][j]];
      e[a].push_back(Edge(ab, b));
      e[b].push_back(Edge(ba, a));
    }
  }
  for (int i = 0; i < m; ++i) {
    sort(e[i].begin(), e[i].end(), CmpA());
    /*
       fprintf(stderr, "* %.2lf %.2lf\n", vp[i].x, vp[i].y);
       for (size_t j = 0; j < e[i].size(); ++j) {
       fprintf(stderr, "> %.2lf %.2lf\n", vp[e[i][j].p].x, vp[e[i][j].p].y);
       }
       */
  }
  ans.clear();
  for (int i = 0; i < m; ++i) {
    for (size_t j = 0; j < e[i].size(); ++j) {
      if (e[i][j].m) {
        continue;
      }
      a = i;
      b = j;
      s = vp[a].x * vp[e[a][b].p].y - vp[a].y * vp[e[a][b].p].x;
      e[a][b].m = true;
      // fprintf(stderr, "\n(%.2lf, %.2lf)\n", vp[a].x, vp[a].y);
      do {
        c = search(e[e[a][b].p], e[a][b].a);
        if (c == -1) {
          s = 0;
          // fprintf(stderr, "-1\n");
          break;
        }
        a = e[a][b].p;
        b = c;
        if (e[a][b].m) {
          s = 0;
          // fprintf(stderr, "mark\n");
          break;
        }
        s += vp[a].x * vp[e[a][b].p].y - vp[a].y * vp[e[a][b].p].x;
        e[a][b].m = true;
        // fprintf(stderr, "(%.2lf, %.2lf)\n", vp[a].x, vp[a].y);
      } while (e[a][b].p != i);
      // fprintf(stderr, "s=%.2lf\n", s);
      if (s > 2 * EPS) {
        // fprintf(stderr, "+ %.2lf\n", s);
        ans.push_back(s);
      }
    }
  }
  sort(ans.begin(), ans.end());	// Wrong answer on test 23 -_-b
  printf("%d\n", (int)ans.size());
  for (size_t i = 0; i < ans.size(); ++i) {
    printf("%.6lf\n", ans[i] / 2);
  }

  return 0;
}

