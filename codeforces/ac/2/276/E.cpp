#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct SegTree {
  int n, *a;

  static int L(int i) { return i << 1; }
  static int R(int i) { return L(i) ^ 1; }

  SegTree(int m) {
    n = 1;
    while (n < m) {
      n += n;
    }
    a = new int[n + n];
    fill(a, a + n + n, 0);
  }

  void add(int p, int pl, int pr, int l, int r, int x) {
    l = max(pl, l);
    r = min(pr, r);
    if (l >= r) {
      return;
    } else if (pl == l && pr == r) {
      a[p] += x;
    } else {
      int pm = (pl + pr) / 2;
      add(L(p), pl, min(pm, pr), l, r, x);
      add(R(p), max(pm, pl), pr, l, r, x);
    }
  }

  void add(int l, int r, int x) {
    add(1, 0, n, l, r, x);
  }

  int get(int i) {
    int ret = 0;
    i += n;
    while (i > 0) {
      ret += a[i];
      i >>= 1;
    }
    return ret;
  }
};

SegTree* st[MAXN];
int id[MAXN], dis[MAXN];
vector<int> e[MAXN];

int main() {
  int n, m, a, b, v;

  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  fill(dis, dis + n, -1);
  n = e[0].size();
  id[0] = n;
  dis[0] = 0;
  for (int i = 0; i < n; ++i) {
    int k = 1;
    for (int j = e[0][i]; ; j = dis[e[j][0]] == -1 ? e[j][0] : e[j][1]) {
      // printf("[%d] %d %d\n", i, j + 1, k);
      id[j] = i;
      dis[j] = k++;
      if (e[j].size() == 1) {
        break;
      }
    }
    st[i] = new SegTree(k);
  }
  st[n] = new SegTree(MAXN);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &v);
    --v;
    if (a == 0) {
      scanf("%d%d", &a, &b);
      if (v == 0) {
        st[n]->add(0, b + 1, a);
      } else if (b < dis[v]) {
        st[id[v]]->add(dis[v] - b, dis[v] + b + 1, a);
      } else {
        st[n]->add(0, b - dis[v] + 1, a);
        st[id[v]]->add(b - dis[v] + 1, dis[v] + b + 1, a);
      }
    } else {
      b = st[n]->get(dis[v]);
      if (v != 0) {
        b += st[id[v]]->get(dis[v]);
      }
      printf("%d\n", b);
    }
  }

  for (int i = 0; i <= n; ++i) {
    delete st[i];
  }

  return 0;
}
