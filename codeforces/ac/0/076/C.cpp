#include <list>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200200;
const int SIGMA = 22;

char str[MAXN];
int lookup[MAXN][SIGMA];
int cost[SIGMA], dis[SIGMA][SIGMA];
int dp[1 << SIGMA], rm[1 << SIGMA];

int main() {
  int n, m, ans, charset, threshold;
  vector<pair<int, int> > v;

  scanf("%d%d%d%s", &n, &m, &threshold, str);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &cost[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &dis[i][j]);
    }
  }
  for (int i = 1; i < (1 << m); ++i) {
    int j = __builtin_ctz(i);
    rm[i] = rm[i ^ (1 << j)] + cost[j];
  }

  charset = 0;  // WA2!!
  for (int i = 0; i < n; ++i) {
    str[i] = (char)(str[i] - 'A');
    charset |= 1 << str[i];
  }
  fill(lookup[n], lookup[n] + m, n);
  for (int i = n - 1; i >= 0; --i) {
    copy(lookup[i + 1], lookup[i + 1] + m, lookup[i]);
    lookup[i][(int)str[i]] = i;
  }

  for (int i = 0; i < m; ++i) {
    if (lookup[0][i] < n) {
      v.push_back({lookup[0][i], i});
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    v[0].first = lookup[i + 1][(int)str[i]];
    for (int j = 1; j < (int)v.size() && v[j - 1].first > v[j].first; ++j) {
      swap(v[j - 1], v[j]);
    }
    if (v.back().first >= n) {
      v.pop_back();
    }

    int mask = 0;
    for (const auto& j: v) {
      int gap = dis[(int)str[i]][j.second];
      dp[mask] += gap;
      dp[mask | (1 << str[i])] -= gap;
      mask |= 1 << j.second;
      dp[mask] -= gap;
      dp[mask | (1 << str[i])] += gap;
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      if ((j & (1 << i)) != 0) {
        dp[j] += dp[j ^ (1 << i)];
      }
    }
  }
  ans = 0;
  for (int i = 0; i < (1 << m); ++i) {
    if ((i & charset) == i && i != charset && dp[i] + rm[i] <= threshold) {
      ++ans;
    }
  }
  printf("%d\n", ans);

  return 0;
}
