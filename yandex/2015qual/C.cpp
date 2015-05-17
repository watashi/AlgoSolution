#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n, m, t, x, y;
  vector<int64_t> a, s;
  vector<vector<int64_t>> f;
  set<pair<int64_t, int>> q;

  scanf("%d", &n);
  a.reserve(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    a.push_back(t);
  }

  scanf("%d", &m);
  f.resize(m);
  s = vector<int64_t>(m, 0);
  for (int i = 0; i < m; ++i) {
    f[i].reserve(n);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &t);
      f[i].push_back(t);
      s[i] += a[j] * t;
    }
    q.insert({s[i], i});
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &t, &x);
    if (t == 1) {
      auto it = q.rbegin();
      for (int j = 0; j < x; ++j) {
        printf("%d ", it->second + 1);
        ++it;
      }
      puts("");
    } else {
      scanf("%d%d", &y, &t);
      --x;
      --y;
      q.erase({s[x], x});
      s[x] -= a[y] * f[x][y];
      f[x][y] = t;
      s[x] += a[y] * f[x][y];
      q.insert({s[x], x});
    }
  }

  return 0;
}
