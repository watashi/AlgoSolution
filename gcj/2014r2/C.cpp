#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

struct Rect {
  int x0, y0, x1, y1;
};

int d[MAXN];
int e[MAXN][MAXN];
Rect rect[MAXN];

int diff(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first > b.first) {
    return diff(b, a);
  } else if (a.second < b.first) {
    return b.first - a.second - 1;
  } else {
    return 0;
  }
}

int dist(const Rect& a, const Rect& b) {
  int dx = diff({a.x0, a.x1}, {b.x0, b.x1});
  int dy = diff({a.y0, a.y1}, {b.y0, b.y1});
  // printf("dx = %d; dy = %d\n", dx, dy);
  return max(dx, dy);
}

int main() {
  int re, w, h, n, m, s, t;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &w, &h, &n);
    s = n;
    t = n + 1;
    m = n + 2;
    for (int i = 0; i < m; ++i) {
      e[i][i] = 0;
    }
    e[s][t] = e[t][s] = w;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d", &rect[i].x0, &rect[i].y0, &rect[i].x1, &rect[i].y1);
      e[i][s] = e[s][i] = rect[i].x0;
      e[i][t] = e[t][i] = (w - 1) - rect[i].x1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        e[i][j] = e[j][i] = dist(rect[i], rect[j]);
      }
    }
    // printf("d[0][1] = %d\n", e[0][1]);

    priority_queue<pair<int, int>> pq;
    fill(d, d + m, -1);
    d[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
      int k, t;
      tie(t, k) = pq.top();
      pq.pop();
      t = -t;
      if (t != d[k]) {
        continue;
      }
      // printf("=> %d %d\n", k, t);

      for (int i = 0; i < m; ++i) {
        if (d[i] == -1 || (d[i] > t + e[k][i])) {
          d[i] = t + e[k][i];
          pq.emplace(-d[i], i);
        }
      }
    }

    printf("Case #%d: %d\n", ri, d[n + 1]);
  }

  return 0;
}

