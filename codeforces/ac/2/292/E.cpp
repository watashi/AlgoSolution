#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int UNDEF = 0x80000000;

struct SegTree {
  int n;
  int off[MAXN + MAXN];

  static int L(int i) { return i << 1; }
  static int R(int i) { return L(i) ^ 1; }

  void init(int m) {
    n = 1;
    while (n < m) {
      n <<= 1;
    }
    fill(off, off + n + n, UNDEF);
  }

  void set(int p, int pl, int pr, int l, int r, int offset) {
    l = max(pl, l);
    r = min(pr, r);
    if (pl == l && pr == r) {
      off[p] = offset;
    } else if (l < r) {
      int pm = (pl + pr) / 2;
      if (off[p] != UNDEF) {
        off[L(p)] = off[p];
        off[R(p)] = off[p];
        off[p] = UNDEF;
      }
      set(L(p), pl, pm, l, r, offset);
      set(R(p), pm, pr, l, r, offset);
    }
  }

  void set(int l, int r, int offset) {
    return set(1, 0, n, l, r, offset);
  }

  int get(int i) {
    int ret = 0;
    i += n;
    while (i > 0) {
      if (off[i] != UNDEF) {
        ret = off[i];
      }
      i >>= 1;
    }
    return ret;
  }
} st;

int a[MAXN + MAXN];

int main() {
  int n, m, x, y, k;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[n + i]);
  }
  st.init(n);
  st.set(0, n, n);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &k, &x);
    --x;
    if (k == 1) {
      scanf("%d%d", &y, &k);
      --y;
      st.set(y, y + k, x - y);
    } else {
      printf("%d\n", a[st.get(x) + x]);
    }
  }

  return 0;
}

