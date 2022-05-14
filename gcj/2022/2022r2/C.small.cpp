#include <bits/stdc++.h>

using namespace std;

namespace {

struct Point {
  long long x, y;
};

long long sqr(long long x) {
  return x * x;
}

struct Solution {
  int n;
  vector<Point> a, b;
  vector<vector<int>> go;
  unordered_set<int> mark;
  vector<pair<int, int>> ret;

  bool gao(int ma, int mb) {
    if (ma == 0 && mb == 0) {
      return true;
    }
    if (!mark.insert((ma << n) | mb).second) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      int j = go[i][mb];
      if (((ma >> i) & 1) != 0 && j < n) {
        // printf("%*s %d => %d\n", 2 * (int)ret.size(), "", i, j);
        ret.emplace_back(i, j);
        if (gao(ma ^ (1 << i), mb ^ (1 << j))) {
          return true;
        }
        ret.pop_back();
      }
    }
    return false;
  }

  vector<pair<int, int>> solve() {
    scanf("%d", &n);
    a.resize(n);
    b.resize(n + 1);
    for (auto& i: a) {
      scanf("%lld%lld", &i.x, &i.y);
    }
    for (auto& i: b) {
      scanf("%lld%lld", &i.x, &i.y);
    }
    rotate(b.begin(), b.begin() + 1, b.end());

    vector<vector<long long>> d(n, vector<long long>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        d[i][j] = sqr(a[i].x - b[j].x) + sqr(a[i].y - b[j].y);
      }
    }

    int m = 1 << n;
    go = vector<vector<int>>(n, vector<int>(m, n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (1 << n); ++j) {
        auto& g = go[i][j];
        for (int k = 0; k < n; ++k) {
          if (((j >> k) & 1) != 0 && d[i][k] <= d[i][g]) {
            g = k;
          }
        }
      }
    }
    ret.reserve(n);
    gao(m - 1, m - 1);
    return ret;
  }
};

} // namespace

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    auto ans = Solution().solve();
    printf("Case #%d: ", ri);
    if (ans.empty()) {
      puts("IMPOSSIBLE");
    } else {
      puts("POSSIBLE");
      for (const auto& i: ans) {
        printf("%d %d\n", i.first + 1, i.second + 2);
      }
    }
  }

  return 0;
}
