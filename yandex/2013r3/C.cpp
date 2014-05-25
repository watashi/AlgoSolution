#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2013;
const int MOD = 1000200013;

inline int addmod(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

struct BIT {
  vector<int> a;

  void init(int n) {
    vector<int>(n + 1).swap(a);
  }

  void add(int i, int v) {
    for (int j = i + 1; j < (int)a.size(); j = (j | (j - 1)) + 1) {
      a[j] = addmod(a[j], v);
    }
  }

  // [0, i)
  int sum(int i) const {
    int ret = 0;
    for (int j = i; j > 0; j = j & (j - 1)) {
      ret = addmod(ret, a[j]);
    }
    return ret;
  }
};

BIT dp[1 << 10];

bool test(int i, int j) {
  return ((i >> j) & 1) != 0;
}

int main() {
  int n, m, h[20];

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &h[i]);
  }
  for (int i = 0; i < (1 << m); ++i) {
    dp[i].init(MAXN);
  }
  dp[0].add(0, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = (1 << m) - 1; j >= 0; --j) {
      for (int k = 0; k < m; ++k) {
        if (!test(j, k)) {
          dp[j | (1 << k)].add(i + h[k], dp[j].sum(i + h[k]));
        }
      }
    }
  }
  printf("%d\n", dp[(1 << m) - 1].sum(MAXN - 1));

  return 0;
}

