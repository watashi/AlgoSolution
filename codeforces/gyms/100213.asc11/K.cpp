#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;

struct Rectangle {
  int x1, y1, x2, y2;
} rect[MAXN];

int common(int x1, int x2, int y1, int y2) {
  return x1 == x2 ? max(0, y2 - y1) : 0;
}

int common(const Rectangle& lhs, const Rectangle& rhs) {
  int ret = 0;
  ret += common(lhs.x1, rhs.x2, max(lhs.y1, rhs.y1), min(lhs.y2, rhs.y2));
  ret += common(lhs.x2, rhs.x1, max(lhs.y1, rhs.y1), min(lhs.y2, rhs.y2));
  ret += common(lhs.y1, rhs.y2, max(lhs.x1, rhs.x1), min(lhs.x2, rhs.x2));
  ret += common(lhs.y2, rhs.y1, max(lhs.x1, rhs.x1), min(lhs.x2, rhs.x2));
  return ret;
}

int main() {
  int n, p, c, l[MAXN], f[MAXN], x[MAXN];
  double s, t, v[MAXN];
  vector<pair<int, int> > e[MAXN];

#ifndef __WATASHI__
  freopen("swimming.in", "r", stdin);
  freopen("swimming.out", "w", stdout);
#endif
  scanf("%d%d%d%d%lf", &n, &rect[0].x2, &rect[0].y2, &p, &s);
  rect[0].x1 = rect[0].y1 = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d%lf", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2, &v[i]);
    l[i] = 2 * (rect[i].x2 - rect[i].x1 + rect[i].y2 - rect[i].y1);
    v[i] *= (rect[i].x2 - rect[i].x1) * (rect[i].y2 - rect[i].y1);
    e[i].clear();
    x[i] = -1;
    f[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      c = common(rect[i], rect[j]);
      if (c > 0) {
        e[i].push_back(make_pair(j, c));
        e[j].push_back(make_pair(i, c));
      }
    }
  }

  x[p] = 0;
  t = 0;
  c = 0;
  for (int i = 1; i <= n; ++i) {
    int k = -1;
    double dt;
    for (int j = 1; j <= n; ++j) {
      if (x[j] == 0 && (k == -1 || v[j] * c / f[j] < dt)) {
        k = j;
        dt = j == p ? v[j] : v[j] * c / f[j];
      }
    }
    x[k] = 1;
    t += dt;
    // printf("%d: %lf %d (%d %d %d %d)\n", k, t, c, f[1], f[2], f[3], f[4]);
    for (int j = 1; j <= n; ++j) {
      if (x[j] == 0) {
        v[j] -= dt * f[j] / c;
      }
    }
    c += l[k];
    c -= 2 * f[k];
    for (int j = 0; j < (int)e[k].size(); ++j) {
      if (x[e[k][j].first] != 1) {
        x[e[k][j].first] = 0;
        f[e[k][j].first] += e[k][j].second;
      }
    }
  }

  printf("%.8lf\n", t / s * 10);

  return 0;
}

