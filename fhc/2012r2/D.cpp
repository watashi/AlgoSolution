#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 32768;
const int MAXD = 5050;

struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
} ds;

vector<pair<int, int> > dp[MAXN];

int main() {
  int re, n, m, a, b;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &m);
    ds.init(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = vector<pair<int, int> >(1, {0, 1});
    }

    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &a, &b);
      --a;
      --b;
      a = ds.getp(a);
      b = ds.getp(b);
      ds.setp(a, b);

      vector<pair<int, int> > v;
      for (auto j: dp[a]) {
        if (j.first < m) {
          v.push_back({j.first + 1, max(j.second, dp[b].back().second + 1)});
        }
      }
      for (auto j: dp[b]) {
        if (j.first < m) {
          v.push_back({j.first + 1, max(j.second, dp[a].back().second + 1)});
        }
      }
      sort(v.begin(), v.end());

      dp[b].clear();
      dp[b].push_back(v[0]);
      for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i].second < dp[b].back().second) {
          dp[b].push_back(v[i]);
        }
      }
    }

    printf("Case #%d: ", ri);
    printf("%d\n", dp[b].back().second);
    fflush(stdout);
  }

  return 0;
}
