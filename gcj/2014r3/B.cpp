#include <set>
#include <cstdio>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXC = 2048;
const int INF = 1'000'000'007;

int cc(int h, int p) {
  assert(h > 0);
  int ret = (h + p - 1) / p;
  assert(ret > 0);
  return ret;
}

int main() {
  int re, p, q, n;
  vector<int> h, g;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &p, &q, &n);
    h.resize(n);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &h[i], &g[i]);
    }

    vector<int> dp(MAXC, -INF);
    dp[1] = 0;
    for (int i = 0; i < n; ++i) {
      // printf("> %d\n", i);
      vector<int> pre(MAXC, -INF);
      pre.swap(dp);

      int cq = cc(h[i], q);
      for (int j = cq; j < MAXC; ++j) {
        dp[j] = max(dp[j], pre[j - cq]);
      }

      set<int> st;
      // printf("%d %d\n", 0, cq);
      for (int j = 0; j < cq; ++j) {
        int cp = cc(h[i] - q * j, p);
        // printf("%d %d\n", cp, j);
        st.insert(cp - j);
      }
      for (int k: st) {
        for (int j = 0; j < MAXC; ++j) {
          if (0 <= j + k && j + k < MAXC) {
            // if (pre[j + k] >= 0) {
            //  printf("upd %d => %d\n", j + k, j);
            // }
            dp[j] = max(dp[j], pre[j + k] + g[i]);
          }
        }
      }
      /*
      for (int j = 0; j < MAXC; ++j) {
        if (dp[j] >= 0) {
          printf("dp[%d] = %d\n", j, dp[j]);
        }
      }
      */
    }

    printf("Case #%d: %d\n", ri, *max_element(dp.begin(), dp.end()));
  }

  return 0;
}
