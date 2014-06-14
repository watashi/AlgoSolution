#include <map>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const int INF = 1'000'000'007;

struct Id {
  map<int, int> mp;

  void clear() {
    mp.clear();
  }

  int size() const {
    return mp.size();
  }

  int operator()(int i) {
    if (mp.count(i) == 0) {
      mp.emplace(i, mp.size());
    }
    return mp[i];
  }
} id;

bool test(int i, int j) {
  return (i >> j) & 1;
}

int main() {
  int re, n, x;
  char ch;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    id.clear();

    basic_string<bool> dp(1 << MAXN, true);
    for (int i = 0; i < n; ++i) {
      scanf(" %c%d", &ch, &x);
      --x;
      if (x >= 0) {
        x = id(x);
      }

      basic_string<bool> pre(1 << MAXN, false);
      pre.swap(dp);
      for (int j = (x == -1 ? 0 : x); j < (x == -1 ? MAXN : x + 1); ++j) {
        for (int k = 0; k < (1 << MAXN); ++k) {
          if (test(k, j) == (ch == 'E') && pre[k ^ (1 << j)]) {
            dp[k] = true;
          }
        }
      }
    }

    x = INF;
    for (int i = 0; i < (1 << MAXN); ++i) {
      if (dp[i]) {
        x = min(x, __builtin_popcount(i));
      }
    }
    printf("Case #%d: ", ri);
    if (x < INF) {
      printf("%d\n", x);
    } else {
      puts("CRIME TIME");
    }
  }

  return 0;
}
