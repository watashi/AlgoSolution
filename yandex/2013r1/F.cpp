#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

int n, m;
string s;
vector<string> v;

int dp[MAXN][2];

void upd(int& lhs, int rhs) {
  lhs = min(lhs, rhs);
}

int main() {
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  n = (int)v.size();
  cin >> s;
  s += '#';

  fill(dp[0], dp[MAXN], INF);
  dp[0][0] = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (dp[i][0] < INF) {
      // printf("dp[%d][%d] = %d\n", i, 0, dp[i][0]);
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < 1; ++k) {
          for (int l = k; l < m && v[j][l] == s[i + (l - k)]; ++l) {
            upd(dp[i + (l - k) + 1][l == m - 1 ? 1 : 0], dp[i][0] + 1);
          }
        }
      }
    }
    if (dp[i][1] < INF) {
      // printf("dp[%d][%d] = %d\n", i, 1, dp[i][1]);
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          for (int l = k; l < m && v[j][l] == s[i + (l - k)]; ++l) {
            upd(dp[i + (l - k) + 1][l == m - 1 ? 1 : 0], dp[i][1] + 1);
          }
        }
      }
    }
  }
  if (dp[(int)s.size() - 1][1] < INF) {
    printf("%d\n", (int)dp[(int)s.size() - 1][1]);
  } else {
    puts("NO");
  }

  return 0;
}

