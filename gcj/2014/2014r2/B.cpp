#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1000000007;

int dp[MAXN][MAXN];

int main() {
  int re, n, m, ans;
  vector<int> a;
  map<int, int> mp;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    a.resize(n);
    mp.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]];
    }

    m = 0;
    for (auto& i: mp) {
      i.second = m++;
    }
    for (int i = 0; i < n; ++i) {
      a[i] = mp[a[i]];
    }

    fill(dp[0], dp[n], INF);
    dp[0][0] = 0;
    for (int k = 0; k < n - 1; ++k) {
      int s = find(a.begin(), a.end(), k) - a.begin();
      a.erase(a.begin() + s);
      for (int i = 0; i <= k; ++i) {
        int j = k - i;
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + s);
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + ((int)a.size() - s));
      }
    }

    ans = INF;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, dp[i][n - 1 - i]);
    }
    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}

