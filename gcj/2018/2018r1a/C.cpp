#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n;
    int p, q, r, w, h;
    vector<pair<int, long double>> v;

    scanf("%d%d", &n, &p);
    v.reserve(n);
    q = r = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &w, &h);
      q += w + h;
      r += min(w, h);
      v.emplace_back(min(w, h), hypotl(w, h));
    }

    vector<long double> dp(r + 1, 0);
    for (const auto& i: v) {
      for (int j = r; j >= i.first; --j) {
        dp[j] = max(dp[j], dp[j - i.first] + i.second);
      }
    }
    long double ans = 2 * (q + dp[min(r, p / 2 - q)]);
    ans = min<long double>(p, ans);
    printf("Case #%d: %.10f\n", ri, (double)ans);
  }

  return 0;
}
