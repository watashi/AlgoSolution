#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXB = 16;
const int MAXN = 1 << MAXB;

vector<llint> gao(int n) {
  int x;
  vector<llint> a(MAXN, 0);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++a[x];
  }
  for (int i = 0; i < MAXN; ++i) {
    int k = (MAXN - 1) ^ i;
    for (int j = k; j > 0; j = (j - 1) & k) {
      a[i] += a[i | j];
    }
  }

  return a;
}

int main() {
  int n, m, q, x;
  vector<llint> a, b, c;

  scanf("%d%d%d", &n, &m, &q);
  a = gao(n);
  b = gao(m);

  c = vector<llint>(MAXN, 0);
  for (int i = 0; i < MAXN; ++i) {
    c[i] = a[i] * b[i];
  }
  for (int i = MAXN - 1; i >= 0; --i) {
    int k = (MAXN - 1) ^ i;
    for (int j = k; j > 0; j = (j - 1) & k) {
      c[i] -= c[i | j];
    }
  }

  for (int i = 0; i < q; ++i) {
    scanf("%d", &x);
    printf("%lld\n", c[x]);
  }

  return 0;
}

/*
   5 6 12
   2 3 5 7 11
   1 2 3 4 5 6
   0 1 2 3 4 5 6 7 8 9 10 11
   */
