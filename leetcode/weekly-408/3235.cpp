class Solution {
public:
  static int64_t sqr(int64_t x) {
    return x * x;
  }

  static int64_t dist2(int64_t x, int64_t y) {
    return sqr(x) + sqr(y);
  }

  static bool check(int64_t x, int64_t y, int64_t r, int64_t x1, int64_t x2) {
    if (x < x1) {
      return dist2(x - x1, y) <= sqr(r);
    } else if (x > x2) {
      return dist2(x - x2, y) <= sqr(r);
    } else {
      return sqr(y) <= sqr(r);
    }
  }

  bool canReachCorner(int X, int Y, vector<vector<int>>& c) {
    const int n = c.size();
    const int TL = n, BR = n + 1;
    vector<vector<int>> e(n + 2);
    for (int i = 0; i < n; ++i) {
      int64_t x1 = c[i][0], y1 = c[i][1], r1 = c[i][2];
      if (check(x1, Y - y1, r1, 0, X) || check(y1, x1, r1, 0, Y)) {
        e[TL].push_back(i);
        e[i].push_back(TL);
      }
      if (check(x1, y1, r1, 0, X) || check(y1, X - x1, r1, 0, Y)) {
        e[BR].push_back(i);
        e[i].push_back(BR);
      }
      for (int j = 0; j < i; ++j) {
        int64_t x2 = c[j][0], y2 = c[j][1], r2 = c[j][2];
        if (dist2(x2 - x1, y2 - y1) <= sqr(r1 + r2)) {
          e[i].push_back(j);
          e[j].push_back(i);
        }
      }
    }

    vector<bool> mark(n + 2, false);
    queue<int> q;
    mark[TL] = true;
    q.push(TL);
    while (!q.empty()) {
      const int i = q.front();
      q.pop();
      for (int j : e[i]) {
        if (!mark[j]) {
          mark[j] = true;
          q.push(j);
        }
      }
    }
    return !mark[BR];
  }
};
